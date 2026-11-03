#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	std::cout << "Brain Copy constructor called" << std::endl;
}
Brain &Brain::operator=(const Brain &obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	std::cout << "Brain Copy assignment operator called" << std::endl;
	return *this;
}

std::string Brain::getIdea(unsigned int index) const
{
	if (index >= 100)
	{
		std::cout << "unable to get idea, index is out of range" << std::endl;
		return "";
	}
	return this->ideas[index];
}

void Brain::setIdea(unsigned int index, const std::string &idea)
{
	if (index >= 100)
	{
		std::cout << "unable to set idea, index is out of range" << std::endl;
		return;
	}
	this->ideas[index] = idea;
}