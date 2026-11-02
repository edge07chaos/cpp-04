#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
		this->type = "WrongCat";
		std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj): WrongAnimal(obj) {
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
	if (this != &obj)
		WrongAnimal::operator=(obj);
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongCat said: meow!" << std::endl;
}