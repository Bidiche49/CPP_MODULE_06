NAME = RealType
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = objs
SRCS_DIR = srcs/
INC_DIR = includes/

SRCS =	$(SRCS_DIR)Base.cpp

OBJS = $(patsubst $(SRCS_DIR)%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

RESET = \033[0m
GREEN = \033[32m
YELLOW = \033[33m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling in progress...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)------------------------$(RESET)"
	@echo "$(GREEN)$(NAME) is compiled!$(RESET)"

$(OBJ_DIR)/%.o: $(SRCS_DIR)%.cpp | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(YELLOW)Removing object files and directory...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Object files and directory removed.$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing the executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Executable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
