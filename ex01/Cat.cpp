#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->brain = new Brain(*obj.brain);
	// for (int i = 0; i < 100; i++)
	// 	this->brain->setIdea(i, obj.brain->getIdea(i));
}

Cat &Cat::operator=(const Cat &obj)
{
	if (this != &obj)
	{
		Animal::operator=(obj);
		// this->brain = new Brain(); - already allocated in constructor

		this->brain->operator=(*obj.brain);
		// for (int i = 0; i < 100; i++)
		// 	this->brain->setIdea(i, obj.brain->getIdea(i));
	}
	std::cout << "Cat Copy assignment operator called" << std::endl;
	return *this;
}

Brain* Cat::getBrain(void) const {
	return this->brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat said: meow!" << std::endl;
}