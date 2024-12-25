################################################################################
##                                MINISHELL                                   ##
################################################################################

NAME    := minishell

BLINK           := \33[5m
BOLD            := \33[1m
CYAN    := \33[1;36m
RESET   := \033[0m
LOG     := printf "[$(CYAN)INFO$(RESET)] %s\n"
LOADING := printf "[$(CYAN)LOADING$(RESET)] %s\r"
SUCCESS := printf "[$(CYAN)SUCCESS$(RESET)] %s\n"

OBJ_DIR  := obj
LIBFT_DIR := libft
INC_DIRS  := include $(LIBFT_DIR)
SRC_DIRS  := cache signals builtins scanner parser parser/grammar
SRC_DIRS  += helpers exec expansion
SRC_DIRS  := $(addprefix src/, $(SRC_DIRS))
SRC_DIRS  += src

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

LIBFT   := $(LIBFT_DIR)/libft.a

HEADERS := minishell.h hash_table.h builtins.h parser.h parser.h tree.h
HEADERS += helpers.h exec.h expansion.h events.h

SOURCES := minishell.c hash_table.c hash_table_utils.c
SOURCES += handlers.c events.c
SOURCES += echo.c pwd.c unset.c cd.c export.c exit.c
SOURCES += scanner.c scanner_utils.c token_word.c parser.c syntax_error.c
SOURCES += tree.c tree_utils.c table.c
SOURCES += rules1.c rules2.c rules3.c rules4.c rules5.c
SOURCES += environ.c environ2.c builtin_pool.c env.c path.c error.c string.c
SOURCES += exec.c incshell.c convcharenv.c exec_cmd.c pcall.c exec_redir.c exec_utils.c exec_pipe.c
SOURCES += exec_list.c exec_heredoc.c exec_subshell.c
SOURCES += exp_utils.c wildcard.c wildcard_utils.c expand.c quotes.c
SOURCES += exit_utils.c heredoc_utils.c exec_builtin.c

SOURCES += $(DEBUG)

OBJS := $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

CFLAGS  := -Wall -Werror -Wextra -g $(addprefix -I,$(INC_DIRS))
LDFLAGS := -L $(LIBFT_DIR) -lft -lreadline

all: $(NAME) no_relink

$(NAME): $(OBJS) | $(LIBFT)
	@$(LOADING) "Linking objects to $@"
	@$(CC) $^ $(LDFLAGS) -o $@ 
	@$(SUCCESS) "Linked $(NAME) to $@"

$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	@$(LOADING) "Compiling $< to $@"
	@$(CC) $(CFLAGS) -c $< -o $@ 
	@$(SUCCESS) "Compiled $< to $@"

$(OBJ_DIR):
	@$(LOADING) "Creating objects directory"
	@mkdir -p $@
	@$(SUCCESS) "Created $(OBJ_DIR)"

$(LIBFT):
	@$(LOADING) "Building libft"
	@make bonus -C $(LIBFT_DIR) --no-print-directory
	@$(SUCCESS) "Built libft"

leaks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
		--suppressions=readline.supp ./$(NAME)

checks: $(NAME)
	valgrind -q --leak-check=full --show-leak-kinds=all --track-fds=yes \
		--track-origins=yes --trace-children=yes \
		--trace-children-skip='*/bin/*,*/sbin/*' \
		--suppressions=readline.supp ./$(NAME)
no_relink:
	@echo "                                                     "
	@echo "$(BOLD)$(BLINK)😊 Don't worry, Mr. Walid! 😊$(RESET)"
	@echo "    My Makefile doesn't relink. 🌟"
	@echo "=================================="
	@echo "        ~ Rami Al Fayad ~ "
	@echo "        ~ Salma  Dalaty ~ "
	@echo "=================================="
clean:
	@$(LOADING) "Removing objects"
	@$(RM) -r $(OBJ_DIR)
	@$(SUCCESS) "Removed objects"

fclean: clean
	@$(LOADING) "Removing $(NAME)"
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR) --no-print-directory --silent
	@$(SUCCESS) "Removed $(NAME) and cleaned libft"

re: fclean all

.PHONY: all clean fclean re
