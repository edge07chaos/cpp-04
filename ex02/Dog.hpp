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
		
		Brain* getBrain(void) const;
		virtual void makeSound(void) const;
};
#endif