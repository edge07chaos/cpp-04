#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria() : type("Default") {
		std::cout << "AMateria Default constructor called" << std::endl;
}

	AMateria::~AMateria() {
	std::cout << "AMateria Destructor called" << std::endl;

	}

	AMateria::AMateria(const AMateria &obj): type(obj.type) {
		std::cout << "AMateria Copy constructor called" << std::endl;
	}

	AMateria::AMateria(std::string const &type): type(type) {
		std::cout << "AMateria parameterized constructor called" << std::endl;

	}

	AMateria& AMateria::operator=(const AMateria &obj) {
		std::cout << "AMateria Copy assignment operator called" << std::endl;
		if (this != &obj)
			this->type = obj.type;
		return *this;
	}

	std::string const& AMateria::getType() const {
		return this->type;
	}

	// virtual AMateria *clone() const = 0;

	void AMateria::use(ICharacter &target) {
			std::cout << "* generic usage of AMateria at " << target.getName() << " *" << std::endl;
	}