#pragma once
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	AMateria *inventory[4];

public:
	Character();
	virtual ~Character();
	Character(const Character &obj);
	Character(const std::string &name);
	Character &operator=(const Character &obj);

	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
};