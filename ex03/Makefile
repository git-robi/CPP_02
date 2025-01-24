NAME = bsp
CXX = c++            
CXXFLAGS = -Wall -Wextra -Werror 
SOURCES = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Fixed.hpp Point.hpp

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp Makefile $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
