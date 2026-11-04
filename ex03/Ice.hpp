#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(const Ice &obj);
	// Ice(std::string const &type);
	Ice &operator=(const Ice &obj);
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif
