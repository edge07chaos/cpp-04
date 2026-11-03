#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	std::cout << "SUBJECT TEST - no leak"<< std::endl;
	std::cout << "Constructors:"<< std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << std::endl;

	std::cout << "Destructors:"<< std::endl;
	delete j; // should not create a leak
	delete i;
	std::cout<<"===================\n" << std::endl;

	std::cout << "SUBJECT TEST - array of Animals with no leak\n"
						<< std::endl;
	int SIZE = 4;
	Animal *animalArray[SIZE];

	std::cout << "CREATING ITEMS OF ARRAY" << std::endl;
	std::cout << "Dogs:" << std::endl;
	for (int i = 0; i < SIZE / 2; i++)
		animalArray[i] = new Dog();
	std::cout<<"===================\n" << std::endl;

	std::cout << "Cats:" << std::endl;
	for (int i = SIZE / 2; i < SIZE; i++)
		animalArray[i] = new Cat();
	std::cout<<"===================\n" << std::endl;

	std::cout << "DEEP COPY" << std::endl;
	Dog dog1;
	Dog dog2(dog1);

	dog1.getBrain()->setIdea(0, "Idea of dog 1");
	dog2 = dog1;

	Dog dog3(dog2);

	std::cout << "\n DISPLAY IDEAS" << std::endl;
	std::cout << "Dog1 - index 0: "<< dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 - index 0: " << dog2.getBrain()->getIdea(0)<< std::endl;
	std::cout << "Dog3 - index 0: " << dog3.getBrain()->getIdea(0)<< std::endl;


	std::cout << "\n CHANGING IDEAS" << std::endl;
	dog1.getBrain()->setIdea(0, "Idea of dog 1 - v2");
	dog2.getBrain()->setIdea(0, "Idea of dog 2");
	dog3.getBrain()->setIdea(0, "Idea of dog 3");


		std::cout << "\n DISPLAY IDEAS" << std::endl;
	std::cout << "Dog1 - index 0: "<< dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 - index 0: " << dog2.getBrain()->getIdea(0)<< std::endl;
	std::cout << "Dog3 - index 0: " << dog3.getBrain()->getIdea(0)<< std::endl;

	std::cout<<"===================\n" << std::endl;


	std::cout << "DELETING ITEMS OF ARRAY" << std::endl;
	std::cout << "Dogs:" << std::endl;
	for (int i = 0; i < SIZE / 2; i++)
		delete animalArray[i];
	std::cout<<"===================\n" << std::endl;

	std::cout << "Cats:" << std::endl;
	for (int i = SIZE / 2; i < SIZE; i++)
		delete animalArray[i];
	std::cout<<"===================\n" << std::endl;

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
	return 0;
}