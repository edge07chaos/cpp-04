#include "Cure.hpp"
#include <iostream>
#include "Logging.hpp"

Cure::Cure() : AMateria("cure")
{
	LOG("Cure Default constructor called");
}

Cure::~Cure()
{
	LOG("Cure Destructor called");
}

Cure::Cure(const Cure &obj) : AMateria(obj)
{
	LOG("Cure Copy constructor called");
}

Cure &Cure::operator=(const Cure &obj)
{
	LOG("Cure Copy assignment operator called");
	if (this != &obj)
		AMateria::operator=(obj);
	return *this;
}

AMateria *Cure::clone() const
{
	Cure *CureMateria = new Cure();
	return CureMateria;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
