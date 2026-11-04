NAME = Interface

#files
OBJS = AMateria.o Cure.o MateriaSource.o Character.o Ice.o main.o
HEADERS = ICharacter.hpp AMateria.hpp Cure.hpp IMateriaSource.hpp MateriaSource.hpp Character.hpp Ice.hpp

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