#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << this->type << " Default constructor called" << std::endl;
}

Cat::~Cat() { std::cout << this->type << " Destructor called" << std::endl; }

Cat::Cat(const Cat &obj): Animal(obj)
{
	std::cout << this->type << " Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
	if (this != &obj)
		Animal::operator=(obj);
	std::cout<< this->type<<" Copy assignment operator called"<<std::endl;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << this->type << " says: meow!" << std::endl;
}