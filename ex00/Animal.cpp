#include <iostream>
#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << this->type << " Default constructor called" << std::endl;
}

Animal::~Animal() { std::cout << this->type << " Destructor called" << std::endl; }

Animal::Animal(const Animal &obj)
{
	std::cout << this->type << " Copy constructor called" << std::endl;
	*this = obj;
}

Animal &Animal::operator=(const Animal &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << this->type << " says: generic sound" << std::endl;
}