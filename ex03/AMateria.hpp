#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type;

public:
	AMateria();
	~AMateria();
	AMateria(const AMateria &obj);
	AMateria(std::string const &type);
	AMateria &operator=(const AMateria &obj);

	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};
#endif