NAME = Interface

#files
 
OBJS = main.o AMateria.o ICharacter.o Ice.o Cure.o
HEADERS = AMateria.hpp ICharacter.hpp Ice.hpp Cure.hpp

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