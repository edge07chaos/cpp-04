#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class Character: public ICharacter
{
	private:
		std::string name;
public:
	Character();
	virtual ~Character();
	Character(const Character& obj);
	Character& operator=(const Character& obj);

	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, Character &target);
};

#endif