#include <iostream>
#include "Logging.hpp"
#include "AMateria.hpp"

AMateria::AMateria() : type("Default")
{
	LOG("AMateria Default constructor called");
}

AMateria::~AMateria()
{
	LOG("AMateria Destructor called");
}

AMateria::AMateria(const AMateria &obj) : type(obj.type)
{
	LOG("AMateria Copy constructor called");
}

AMateria::AMateria(std::string const &type) : type(type)
{
	LOG("AMateria parameterized constructor called");
}

AMateria &AMateria::operator=(const AMateria &obj)
{
	LOG("AMateria Copy assignment operator called");
	// -- an Ice/Cure (or other material) is always an Ice/Cure
	// if (this != &obj) this->type = obj.type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

// virtual AMateria *clone() const = 0;

void AMateria::use(ICharacter &target)
{
	std::cout << "* generic usage of AMateria at " << target.getName() << " *" << std::endl;
}