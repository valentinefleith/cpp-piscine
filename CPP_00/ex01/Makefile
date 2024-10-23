NAME = phonebook

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
OBJS = $(SRCS:%.cpp=%.o)

.PHONY: all
all: $(NAME)

%.o: %.cpp
	@echo Compiling $<
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "phonebook ready."

.PHONY: clean
clean:
	@echo Cleaning up object files	
	@rm -rf $(OBJS)

.PHONY: fclean
fclean: clean
	@rm -rf $(NAME)

.PHONY: re
re: fclean all
