#include <iostream>
#include "Logging.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	LOG("MateriaSource Default constructor called");
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	LOG("MateriaSource Destructor called");
	for (int i = 0; i < 4; i++)
		delete this->slot[i];
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	LOG("MateriaSource Copy constructor called");
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
	LOG("MateriaSource Copy assignment operator called");
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
	AMateria *tmp;
	for (int i = 0; i < 4; i++)
	{
		tmp = this->slot[i];
		if (tmp && tmp->getType() == type)
			return tmp->clone();
	}
	return 0;
}