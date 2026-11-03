#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== 1. SUBJECT TEST - BASIC ALLOCATION & DESTRUCTION ===" << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "\nDeleting single objects:" << std::endl;
	delete j; // Polymorphic deletion
	delete i;
	std::cout << "=========================================\n"
						<< std::endl;

	std::cout << "=== 2. SUBJECT TEST - ANIMAL ARRAY ===" << std::endl;
	int SIZE = 4;
	Animal *animalArray[SIZE];

	std::cout << "Creating Dogs:" << std::endl;
	for (int idx = 0; idx < SIZE / 2; idx++)
		animalArray[idx] = new Dog();

	std::cout << "\nCreating Cats:" << std::endl;
	for (int idx = SIZE / 2; idx < SIZE; idx++)
		animalArray[idx] = new Cat();

	std::cout << "\nDeleting Array Items:" << std::endl;
	for (int idx = 0; idx < SIZE; idx++)
		delete animalArray[idx];
	std::cout << "=========================================\n"
						<< std::endl;

	std::cout << "=== 3. DEEP COPY TEST - DOG ===" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "Dog 1 initial idea");

	Dog dog2(dog1); // Copy Constructor
	Dog dog3;
	dog3 = dog1; // Copy Assignment Operator

	std::cout << "\n--- Initial Ideas ---" << std::endl;
	std::cout << "Dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog3 idea 0: " << dog3.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n--- Modifying Ideas Independently ---" << std::endl;
	dog1.getBrain()->setIdea(0, "Dog 1 updated idea");
	dog2.getBrain()->setIdea(0, "Dog 2 unique idea");
	dog3.getBrain()->setIdea(0, "Dog 3 unique idea");

	std::cout << "Dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog3 idea 0: " << dog3.getBrain()->getIdea(0) << std::endl;

	std::cout << "Dog1 idea 0 after self-assign: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "=========================================\n"
						<< std::endl;

	std::cout << "=== 4. DEEP COPY TEST - CAT ===" << std::endl;
	Cat cat1;
	cat1.getBrain()->setIdea(0, "Cat 1 initial idea");

	Cat cat2(cat1);
	cat1.getBrain()->setIdea(0, "Cat 1 updated idea");

	std::cout << "Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << "=========================================\n"
						<< std::endl;

	return 0;
}

// previous main
/* std::cout << "=== 1. SUBJECT BASIC POLYMORPHISM TEST ===" << std::endl;
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
 */