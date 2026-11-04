#include "Ice.hpp"
#include <iostream>
#include "Logging.hpp"

Ice::Ice() : AMateria("ice")
{
	LOG("Ice Default constructor called");
}

Ice::~Ice()
{
	LOG("Ice Destructor called");
}

Ice::Ice(const Ice &obj) : AMateria(obj)
{
	LOG("Ice Copy constructor called");
}

// Ice(std::string const &type);

Ice &Ice::operator=(const Ice &obj)
{
	LOG("Ice Copy assignment operator called");
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
