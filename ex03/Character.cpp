#include "Logging.hpp"
#include "Character.hpp"

Character::Character() : name("")
{
	LOG("Character Default constructor called");
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character()
{
	LOG("Character Destructor called");
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}

Character::Character(const std::string &name) : name(name)
{
	LOG("Character parameterized constructor called");
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character &obj) : name(obj.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (obj.inventory[i])
			this->inventory[i] = obj.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	LOG("Character Copy constructor called");
}

Character &Character::operator=(const Character &obj)
{
	LOG("Character Copy assignment operator called");
	if (this != &obj)
	{
			this->name = obj.name;
			for (int i = 0; i < 4; i++)
			{
				delete this->inventory[i];
				if (obj.inventory[i])
					this->inventory[i] = obj.inventory[i]->clone();
				else
					this->inventory[i] = NULL;
		}
	}
	return *this;
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if ((idx < 0 || idx > 3) || !this->inventory[idx])
		return;
	this->inventory[idx]->use(target);
}