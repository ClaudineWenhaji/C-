NAME		= phonebook

CC		= c++
CFLAGS          = -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp PhoneBook.cpp Contact.cpp
OBJS            = $(SRCS:%.cpp=%.o)

GREEN           = \033[0;32m
RED             = \033[0;31m
YELLOW          = \033[0;33m
BLUE 		= \033[0;34m
RESET           = \033[0m

all:		$(NAME)

%.o: %.cpp
	@printf "$(YELLOW)Compiling $<...$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@printf "$(YELLOW) Compiling object files [$(NAME)]...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 
	@printf "$(GREEN) Finished [$(NAME)]$(RESET)"

clean:
	@printf "$(RED)Deleting object files...$(RESET)\n"
	@rm -f $(OBJS)

fclean: clean
	@printf "$(RED)Deleting executables $(NAME)...$(RESET)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
