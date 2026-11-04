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

/**
Ice and Cure are specific, concrete implementations of AMateria.

An Ice materia's type should always be "ice", and a Cure materia's type
should always be "cure".

ex: Ice myIce("fire"); // An Ice object with type "fire"? - no way bro!

that is why in Ice.{hpp. cpp} and Cure.{hpp. cpp} we don't need to mention
	Ice(std::string const &type); or Cure(std::string const &type);

this constructor is just used here in AMaterial, so we can implement
	Ice::Ice(): AMaterial("ice") and Cure::Cure(): AMaterial("cure")
 */