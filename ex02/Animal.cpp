#include <iostream>
#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::~Animal() { std::cout << "Animal Destructor called" << std::endl; }

Animal::Animal(const Animal &obj) : type(obj.type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

std::string Animal::getType(void) const
{
	return this->type;
}

// don't need to be implemented, since it is pure virtual
// void Animal::makeSound(void) const
// {
// 	std::cout << "Animal makes a very generic sound" << std::endl;
// }