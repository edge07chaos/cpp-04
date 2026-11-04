#include <iostream>
#include <sstream>
#include <string>

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

static int g_pass = 0;
static int g_fail = 0;

static void check(bool ok, const char *expr, int line)
{
	if (ok)
	{
		++g_pass;
		std::cout << GREEN << "[ OK ] " << RESET << expr << std::endl;
	}
	else
	{
		++g_fail;
		std::cout << RED << "[FAIL] " << RESET << expr
				  << " (main.cpp:" << line << ")" << std::endl;
	}
}

#define CHECK(cond) check((cond), #cond, __LINE__)

static void section(const std::string &title)
{
	std::cout << "\n" << CYAN << "=== " << title << " ===" << RESET << std::endl;
}

// Expected output of Ice::use / Cure::use
static std::string iceMsg(const std::string &target)
{
	return "* shoots an ice bolt at " + target + " *\n";
}

static std::string cureMsg(const std::string &target)
{
	return "* heals " + target + "'s wounds *\n";
}

// Runs c.use(idx, target) and returns whatever it printed to std::cout
static std::string captureUse(ICharacter &c, int idx, ICharacter &target)
{
	std::ostringstream oss;
	std::streambuf *old = std::cout.rdbuf(oss.rdbuf());
	c.use(idx, target);
	std::cout.rdbuf(old);
	return oss.str();
}

// Same, but directly on a Materia
static std::string captureMateriaUse(AMateria &m, ICharacter &target)
{
	std::ostringstream oss;
	std::streambuf *old = std::cout.rdbuf(oss.rdbuf());
	m.use(target);
	std::cout.rdbuf(old);
	return oss.str();
}

/* ------------------------------------------------------------------ */

static void testSubject()
{
	section("Subject main (visible output)");

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

static void testPolymorphism()
{
	section("Materia: clone, type, use, virtual destructor");

	Character target("target");

	AMateria *ice = new Ice();
	AMateria *iceClone = ice->clone();
	CHECK(iceClone != ice);
	CHECK(iceClone->getType() == "ice");
	CHECK(captureMateriaUse(*iceClone, target) == iceMsg("target"));

	// clone of a clone, through a const reference
	const AMateria &constRef = *iceClone;
	AMateria *iceClone2 = constRef.clone();
	CHECK(iceClone2 != iceClone);
	CHECK(iceClone2->getType() == "ice");

	AMateria *cure = new Cure();
	AMateria *cureClone = cure->clone();
	CHECK(cure->getType() == "cure");
	CHECK(cureClone->getType() == "cure");
	CHECK(captureMateriaUse(*cureClone, target) == cureMsg("target"));

	// Deleting through the base pointer must call the derived destructor
	delete ice;
	delete iceClone;
	delete iceClone2;
	delete cure;
	delete cureClone;
}

static void testMateriaSource()
{
	section("MateriaSource: learn / create");

	MateriaSource src;

	CHECK(src.createMateria("ice") == NULL);   // nothing learned yet
	src.learnMateria(NULL);                    // must not crash or use a slot

	src.learnMateria(new Ice());
	src.learnMateria(new Cure());

	AMateria *a = src.createMateria("ice");
	AMateria *b = src.createMateria("ice");
	AMateria *c = src.createMateria("cure");
	CHECK(a != NULL && a->getType() == "ice");
	CHECK(b != NULL && b->getType() == "ice");
	CHECK(c != NULL && c->getType() == "cure");
	CHECK(a != b);                             // each call returns a new object

	CHECK(src.createMateria("unknown") == NULL);
	CHECK(src.createMateria("") == NULL);
	CHECK(src.createMateria("ICE") == NULL);   // case-sensitive

	delete a;
	delete b;
	delete c;

	// Fill the 4 slots, then try a 5th: ignored, so we still own it
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());
	AMateria *extra = new Ice();
	src.learnMateria(extra);
	delete extra;

	AMateria *still = src.createMateria("cure");
	CHECK(still != NULL && still->getType() == "cure");
	delete still;
}

static void testCharacterInventory()
{
	section("Character: equip / use / unequip");

	Character me("me");
	Character bob("bob");
	Character nameless;

	CHECK(me.getName() == "me");
	CHECK(nameless.getName() == "");

	// Nothing equipped yet
	me.equip(NULL);
	CHECK(captureUse(me, 0, bob) == "");

	AMateria *m[4];
	m[0] = new Ice();
	m[1] = new Cure();
	m[2] = new Ice();
	m[3] = new Cure();
	for (int i = 0; i < 4; i++)
		me.equip(m[i]);

	CHECK(captureUse(me, 0, bob) == iceMsg("bob"));
	CHECK(captureUse(me, 1, bob) == cureMsg("bob"));
	CHECK(captureUse(me, 2, bob) == iceMsg("bob"));
	CHECK(captureUse(me, 3, bob) == cureMsg("bob"));
	CHECK(captureUse(me, 0, me) == iceMsg("me"));   // using on itself

	// Invalid indexes
	CHECK(captureUse(me, -1, bob) == "");
	CHECK(captureUse(me, 4, bob) == "");
	CHECK(captureUse(me, 100, bob) == "");

	// Inventory full: 5th Materia is ignored, we still own it
	AMateria *overflow = new Ice();
	me.equip(overflow);
	delete overflow;
	CHECK(captureUse(me, 0, bob) == iceMsg("bob")); // still intact

	// Unequip: must NOT delete, we own the pointer now
	me.unequip(1);
	CHECK(captureUse(me, 1, bob) == "");
	delete m[1];

	me.unequip(1);      // already empty
	me.unequip(-1);     // invalid
	me.unequip(4);      // invalid
	CHECK(captureUse(me, 0, bob) == iceMsg("bob"));
	CHECK(captureUse(me, 2, bob) == iceMsg("bob"));

	// Equip goes to the first free slot (slot 1 here)
	AMateria *replacement = new Ice();
	me.equip(replacement);
	CHECK(captureUse(me, 1, bob) == iceMsg("bob"));

	// m[0], m[2], m[3] and replacement are deleted by ~Character()
}

static void testDeepCopyCharacter()
{
	section("Character: copy constructor is a deep copy");

	Character target("target");

	// Copy must survive the death of the original
	Character *orig = new Character("orig");
	orig->equip(new Ice());
	orig->equip(new Cure());
	Character copy(*orig);
	CHECK(copy.getName() == "orig");
	CHECK(captureUse(copy, 0, target) == iceMsg("target"));
	delete orig;
	CHECK(captureUse(copy, 0, target) == iceMsg("target"));
	CHECK(captureUse(copy, 1, target) == cureMsg("target"));
	CHECK(captureUse(copy, 2, target) == "");

	// Changing the original's inventory must not affect the copy
	Character a("a");
	AMateria *p = new Ice();
	a.equip(p);
	Character b(a);
	a.unequip(0);
	delete p;
	CHECK(captureUse(a, 0, target) == "");
	CHECK(captureUse(b, 0, target) == iceMsg("target"));
}

static void testAssignmentCharacter()
{
	section("Character: assignment operator");

	Character target("target");
	Character x("x");
	Character y("y");

	x.equip(new Ice());
	x.equip(new Cure());

	// y already holds Materias: they must be freed by operator=
	y.equip(new Cure());
	y.equip(new Cure());
	y.equip(new Cure());

	y = x;
	CHECK(y.getName() == "x");
	CHECK(captureUse(y, 0, target) == iceMsg("target"));
	CHECK(captureUse(y, 1, target) == cureMsg("target"));
	CHECK(captureUse(y, 2, target) == "");
	CHECK(captureUse(y, 3, target) == "");

	// Self-assignment must be safe
	Character &ref = y;
	y = ref;
	CHECK(captureUse(y, 0, target) == iceMsg("target"));
	CHECK(captureUse(y, 1, target) == cureMsg("target"));

	// Independence after assignment
	x.equip(new Ice());
	CHECK(captureUse(x, 2, target) == iceMsg("target"));
	CHECK(captureUse(y, 2, target) == "");

	// Chained assignment
	Character z("z");
	z = y = x;
	CHECK(z.getName() == "x");
	CHECK(captureUse(z, 2, target) == iceMsg("target"));
}

static void testMateriaSourceCopy()
{
	section("MateriaSource: copy constructor / assignment");

	MateriaSource *orig = new MateriaSource();
	orig->learnMateria(new Ice());

	MateriaSource copy(*orig);
	delete orig;                               // copy must survive

	AMateria *m = copy.createMateria("ice");
	CHECK(m != NULL && m->getType() == "ice");
	delete m;
	CHECK(copy.createMateria("cure") == NULL);

	MateriaSource other;
	other.learnMateria(new Cure());
	other = copy;                              // old content must be replaced
	CHECK(other.createMateria("cure") == NULL);
	AMateria *n = other.createMateria("ice");
	CHECK(n != NULL && n->getType() == "ice");
	delete n;

	MateriaSource &ref = other;
	other = ref;                               // self-assignment
	AMateria *k = other.createMateria("ice");
	CHECK(k != NULL && k->getType() == "ice");
	delete k;
}

static void testFullFlow()
{
	section("Full flow: source -> character -> unequip -> re-equip");

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *hero = new Character("hero");
	ICharacter *dummy = new Character("dummy");

	AMateria *created[5];
	created[0] = src->createMateria("ice");
	created[1] = src->createMateria("cure");
	created[2] = src->createMateria("ice");
	created[3] = src->createMateria("cure");
	created[4] = src->createMateria("ice");
	for (int i = 0; i < 4; i++)
		hero->equip(created[i]);
	hero->equip(created[4]);                   // ignored (full)
	delete created[4];                         // so we free it ourselves

	CHECK(captureUse(*hero, 3, *dummy) == cureMsg("dummy"));
	hero->unequip(3);
	CHECK(captureUse(*hero, 3, *dummy) == "");
	hero->equip(created[3]);                   // equip the very same Materia back
	CHECK(captureUse(*hero, 3, *dummy) == cureMsg("dummy"));

	CHECK(src->createMateria("fire") == NULL);
	hero->equip(NULL);

	delete dummy;
	delete hero;
	delete src;
}

int main()
{
	testSubject();
	testPolymorphism();
	testMateriaSource();
	testCharacterInventory();
	testDeepCopyCharacter();
	testAssignmentCharacter();
	testMateriaSourceCopy();
	testFullFlow();

	std::cout << "\n" << CYAN << "=== Summary ===" << RESET << std::endl;
	std::cout << GREEN << g_pass << " passed" << RESET << ", "
			  << (g_fail ? RED : GREEN) << g_fail << " failed" << RESET
			  << std::endl;
	return g_fail ? 1 : 0;
}