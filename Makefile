# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbelhomm <tbelhomm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/24 20:21:03 by charles           #+#    #+#              #
#    Updated: 2022/05/18 12:03:45 by tbelhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_CONTAINERS_DIR = ../lib
PYTHON = python3
PRETTIER = prettier.py
NAME = ft_containers_test
SEGV_WRAPPER = segv_wrapper.sh
SEGV_WRAPPER_OUT = segv_wrapper.out
SRC_DIR = src

CXX = c++
CXXFLAGS = -std=c++98 -O0 -Wall -Wextra -I$(FT_CONTAINERS_DIR) -I.

SRC = $(shell find $(SRC_DIR) -type f -name '*.cpp')
OBJ = $(SRC:.cpp=.o)
OBJ_STD = $(SRC:.cpp=.std.o)
INC = ft_containers_test.hpp

run: all
	@time -f "total duration: %E" ./$(NAME) $(SEGV_WRAPPER_OUT) $(PRETTIER) > ft.out 2>&1
	@time -f "total duration: %E" ./std.$(NAME) $(SEGV_WRAPPER_OUT) $(PRETTIER) > std.out 2>&1
	@./split_duration.sh ft.out
	@./split_duration.sh std.out
	diff ft.out.returns std.out.returns | tee diff.out | cat
	@paste ft.out.duration std.out.duration > duration.out
	@rm ft.out.* std.out.*
	@sed -i -e 's/ //g' duration.out
	@sed -i -e 's/\./,/g' duration.out

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_STD)
	$(CXX) -o $@ $(OBJ)
	$(CXX) -o std.$@ $(OBJ_STD)

$(SRC_DIR)/vector_test.o: $(SRC_DIR)/vector_test.cpp $(INC) $(FT_CONTAINERS_DIR)/vector.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(SRC_DIR)/stack_test.o: $(SRC_DIR)/stack_test.cpp $(INC) $(FT_CONTAINERS_DIR)/stack.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o: %.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	rm -f std.$(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f std.$(NAME)

re: fclean all
