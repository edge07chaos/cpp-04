NAME = Brain

#files
 
OBJS = main.o Animal.o Dog.o Cat.o WrongCat.o WrongAnimal.o Brain.o
HEADERS = Animal.hpp Dog.hpp Cat.hpp WrongCat.hpp WrongAnimal.hpp Brain.hpp

#compiler conf.
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

#commands
DELETE = rm -rf
COMP = $(CXX) $(CXXFLAGS)

#targets
all: $(NAME)

$(NAME): $(OBJS)
	$(COMP) -o $@ $^

$(OBJS): $(HEADERS)

clean:
	$(DELETE) $(OBJS)

fclean: clean
	$(DELETE) $(NAME)

re: fclean all

.PHONY: all clean fclean re