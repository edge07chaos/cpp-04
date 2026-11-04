#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria()
{
	this->type = "ice";
	std::cout << "Ice Default constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice &obj) : AMateria(obj)
{
	std::cout << "Ice Copy constructor called" << std::endl;
}

// Ice(std::string const &type);

Ice &Ice::operator=(const Ice &obj)
{
	std::cout << "AMateria Copy assignment operator called" << std::endl;
	if (this != &obj)
		AMateria::operator=(obj);
	return *this;
}

AMateria *Ice::clone() const
{
	Ice *iceMateria = new Ice();
	return iceMateria;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
