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
	
}
Brain &Brain::operator=(const Brain &obj)
{
}