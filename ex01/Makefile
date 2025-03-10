# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 11:13:15 by rgiambon          #+#    #+#              #
#    Updated: 2025/03/10 11:13:28 by rgiambon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = TowardsAMoreUsefulFixed-pointNumberClass
CXX = c++            
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 
SOURCES = main.cpp Fixed.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Fixed.hpp

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
