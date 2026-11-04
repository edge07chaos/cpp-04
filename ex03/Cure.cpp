#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria()
{
	this->type = "Cure";
	std::cout << "Cure Default constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(const Cure &obj) : AMateria(obj)
{
	std::cout << "Cure Copy constructor called" << std::endl;
}

// Cure(std::string const &type);

Cure &Cure::operator=(const Cure &obj)
{
	std::cout << "AMateria Copy assignment operator called" << std::endl;
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
	std::cout << "* heals " << target.getName() << " ’s wounds *" << std::endl;
}
