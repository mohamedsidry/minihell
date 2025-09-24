
# Output executable name

NAME = minishell

# Compiling flags

CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g
CSTAGE = -c

# Cleaning flags

RM = rm
RMFLAGS = -fr



# Sources Includes and Depandencies .

MAIN 	=	main.c
SRC 	=	src/helper/proreadline.c \
			src/helper/error.c src/helper/concat3.c \
			src/helper/ltrim.c src/helper/is_space.c \
			src/helper/ft_strcmp.c src/helper/ft_realloc.c \
			src/helper/free2d.c src/helper/append_array.c \
			src/helper/serializers.c src/helper/nullstr.c \
			src/helper/is_operator.c src/helper/is_redirection.c src/helper/is_builtin.c \
			src/helper/remove_quotes.c src/helper/pipe_close.c src/helper/is_expandable.c src/helper/expand_handler.c \
			src/helper/find_replace.c \
			src/env/env_handler.c src/env/env_crud.c \
			src/env/node_crud.c src/env/helpers.c \
			src/env/getprefix.c src/env/getsuffix.c \
			src/env/env_serializer.c src/env/env_export.c \
			src/env/env_unset.c src/lexical/lexer.c \
			src/lexical/syntax.c src/lexical/tokenizer.c \
			src/lexical/token_handler.c \
			src/lexical/formater.c \
			src/cmd/cmd_addback.c \
			src/cmd/cmd_clear.c \
			src/cmd/cmd_crud.c \
			src/cmd/cmd_last.c \
			src/cmd/cmd_iter.c \
			src/cmd/cmd_length.c \
			src/cmd/cmd_trim.c \
			src/cmd/cmd_buildin.c \
			src/execution/executor.c \
			src/execution/heredoc_manager.c \
			src/cmd/cmd_expand.c \
			src/cmd/cmd_iter2.c \
			src/cmd/cmd_expandstatus.c \
			src/cmd/cmd_expandprev.c \
			src/helper/has_redirections.c \
			src/cmd/cmd_expandredirection.c \
			src/cmd/cmd_removequotes.c


TEST = test/print_tokens.c test/print_commands.c
SRCS = $(MAIN) $(SRC) $(TEST)

INCLUDES =	include/main.h include/utils.h include/typedef.h 

# LIBFT 

LIBFTARC	= libft/libft.a
LIBFTPATH	= libft/
LIBFT = libft


# LIB FOR READLINE and addhitory functions !

DEPLIB = -lreadline


OBJS = $(SRCS:.c=.o)

%.o:%.c $(INCLUDES)
	@echo "\033[1;33m⚙️​ compiling :\033[0m\033[0;35m $< \033[0m"
	@$(CC) $(CFLAGS) $(CSTAGE) $< -o $@

$(NAME): $(LIBFTARC) $(OBJS)
	@echo "\033[1;33m​🔗​​linking   :\033[0m\033[0;35m $@ \033[0m"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTARC) $(DEPLIB) -I$(LIBFTPATH) -o $@

	@echo "\033[1;33m🚀$(NAME) : \033[0mbuilding finished !"


clean:
	@$(RM) $(RMFLAGS) $(OBJS)
	@make -C $(LIBFTPATH) clean --no-print-directory

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)
	@make -C $(LIBFTPATH) fclean --no-print-directory
re: fclean all


all: $(NAME)

$(LIBFTARC) :
	@make -C $(LIBFTPATH) --no-print-directory


.PHONY: clean fclean re all debug run norms $(LIBFT)

run: $(NAME) clean
	@clear
	@./$(NAME)

debug:  
	@make run DEBUGMODE=1 SANITIZER=1 TESTUNIT=1

fvrun: clean $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

vrun: clean $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)


norms:
	@echo $(CHECKINGNORMS)
	@norminette | grep 'Error!' && echo $(KO) || echo $(OK)

CHECKINGNORMS = "\033[1;33mNorminette ...\033[0m"


OK="\033[1;32mNorminette OK!\033[0m"
KO="\033[1;31mNorminette KO!\033[0m"
