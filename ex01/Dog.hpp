#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Dog: public Animal {
	private:
		Brain* brain;
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);
		
		virtual void makeSound(void) const;
};
#endif