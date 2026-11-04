#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	virtual ~Ice();
	Ice(const Ice &obj);
	Ice &operator=(const Ice &obj);
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};