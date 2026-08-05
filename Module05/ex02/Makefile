name		= form

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJS		= $(SRCS:%.cpp=%.o)

GREEN		= \033[0;32m
RED			= \033[0;31m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
RESET		= \033[0m

all:		$(name)

%.o: %.cpp $(HEADERS)
	@printf "$(YELLOW)Compiling $<...$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(name): $(OBJS)
	@printf "$(YELLOW) Compiling object files [$(name)]...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(name)
	@printf "$(GREEN) Finished [$(name)]$(RESET)"

clean:
	@printf "$(RED)Deleting object files...$(RESET)\n"
	@rm -f $(OBJS)

fclean: clean
	@printf "$(RED)Deleting executables $(name)...$(RESET)\n"
	@rm -f $(name)

re: fclean all

test: $(name)
	valgrind --leak-check=full ./form

.PHONY: all clean fclean re
