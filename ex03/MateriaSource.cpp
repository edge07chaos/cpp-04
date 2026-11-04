#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->slot[i];
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	std::cout << "MateriaSource Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (obj.slot[i])
			this->slot[i] = obj.slot[i]->clone();
		else
			this->slot[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->slot[i];

			if (obj.slot[i])
				this->slot[i] = obj.slot[i]->clone();
			else
				this->slot[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!this->slot[i])
		{
			this->slot[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (type != "ice" && type != "cure")
		return 0;
	AMateria *tmp;
	for (int i =0; i<4;i++) {
		tmp = this->slot[i];
		if (tmp && tmp->getType() == type)
			return tmp->clone();
	}
}