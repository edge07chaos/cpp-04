#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== 1. SUBJECT BASIC POLYMORPHISM TEST ===" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "\n--- Checking Types & Sounds ---" << std::endl;
	std::cout << "Type: " << j->getType() << " -> Sound: ";
	j->makeSound();
	std::cout << "Type: " << i->getType() << " -> Sound: ";
	i->makeSound();
	std::cout << "Type: " << meta->getType() << " -> Sound: ";
	meta->makeSound();

	std::cout << "\n--- Dynamic Deletion (Virtual Destructors) ---" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n=== 2. NON-POLYMORPHIC TEST (WRONG ANIMAL) ===" << std::endl;
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << "\n--- Checking Types & Sounds ---" << std::endl;
	std::cout << "Type: " << wrongCat->getType() << " -> Sound: ";
	wrongCat->makeSound();
	std::cout << "Type: " << wrongMeta->getType() << " -> Sound: ";
	wrongMeta->makeSound();

	std::cout << "\n--- Non-Virtual Deletion ---" << std::endl;
	delete wrongMeta;
	delete wrongCat;

	std::cout << "\n=== 3. ORTHODOX CANONICAL FORM CHECKS ===" << std::endl;
	std::cout << "\n--- Copy Constructor Test ---" << std::endl;
	Cat originalCat;
	Cat copyCat(originalCat);
	std::cout << "Copy Cat Type: " << copyCat.getType() << std::endl;

	std::cout << "\n--- Copy Assignment Operator Test ---" << std::endl;
	Dog originalDog;
	Dog assignedDog;
	assignedDog = originalDog;
	std::cout << "Assigned Dog Type: " << assignedDog.getType() << std::endl;

	std::cout << "\n=== 4. END OF MAIN (STACK DESTRUCTION) ===" << std::endl;
	return 0;
}