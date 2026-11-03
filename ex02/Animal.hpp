#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &obj);
	Animal &operator=(const Animal &obj);

	std::string getType(void) const;
	virtual void makeSound(void) const;
};
#endif