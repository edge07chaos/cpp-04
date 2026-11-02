#include "Animal.hpp"
#include "Cat.hpp"

int main(void)
{
	const Animal *meta = new Cat();
	meta->makeSound();
	delete meta;

	return 0;
}