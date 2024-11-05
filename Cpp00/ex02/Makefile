NAME = account

CC = c++
CXXFLAGS = -Wall -Wextra -std=c++98
# CXXFLAGS += -Werror

SRCS = tests.cpp Account.cpp
OBJS = $(SRCS:%.cpp=%.o)

.PHONY: all
all: $(NAME)

%.o: %.cpp
	@echo Compiling $<
	@$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "account ready."

.PHONY: clean
clean:
	@echo Cleaning up object files	
	@rm -rf $(OBJS)

.PHONY: fclean
fclean: clean
	@rm -rf $(NAME)

.PHONY: re
re: fclean all
