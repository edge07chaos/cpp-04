#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::~Cat() { std::cout << "Cat Destructor called" << std::endl; }

Cat::Cat(const Cat &obj): Animal(obj)
{
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
	if (this != &obj)
		Animal::operator=(obj);
	std::cout<< "Cat Copy assignment operator called"<<std::endl;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat said: meow!" << std::endl;
}