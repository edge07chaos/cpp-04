#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Destructor called" << std::endl;
}
Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
	if (this != &obj)
		Animal::operator=(obj);
	std::cout << "Dog Copy assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog said: woof!" << std::endl;
}