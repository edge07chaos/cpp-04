#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	virtual ~Cure();
	Cure(const Cure &obj);
	Cure &operator=(const Cure &obj);
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};