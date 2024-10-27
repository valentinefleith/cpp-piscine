NAME = phonebook

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp PhoneBook.cpp Contact.cpp
OBJS = $(SRCS:%.cpp=%.o)

.PHONY: all
all: $(NAME)

%.o: %.cpp
	@echo Compiling $<
	@$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)
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
