#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &obj): type(obj.type)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	return *this;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal made a generic sound!" << std::endl;
}