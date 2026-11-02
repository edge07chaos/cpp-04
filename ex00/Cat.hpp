#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat& obj);
		Cat& operator=(const Cat& obj);
		
		virtual void makeSound(void) const;
};
#endif