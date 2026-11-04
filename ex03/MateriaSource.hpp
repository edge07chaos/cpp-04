#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *slot[4];

public:
	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource(const MateriaSource &obj);
	MateriaSource &operator=(const MateriaSource &obj);

	virtual void learnMateria(AMateria *);
	virtual AMateria *createMateria(std::string const &type);
};