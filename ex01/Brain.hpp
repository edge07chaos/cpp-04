#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
	public:
		Brain();
		~Brain();
		Brain(const Brain& obj);
		Brain& operator=(const Brain& obj);

		std::string ideas[100];
};

#endif