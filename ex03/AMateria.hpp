#pragma once

#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type;

public:
	AMateria();
	virtual ~AMateria();
	AMateria(const AMateria &obj);
	AMateria(std::string const &type);
	AMateria &operator=(const AMateria &obj);

	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};