NAME = pipex

SRC = pipex.c\
pipex_utils_split.c\
pipex_utils.c\
pipex_utils2.c\
pipex_strchr.c\

SRCB = bonus/pipex_bonus.c\
bonus/pipex_utils_bonus.c\
bonus/pipex_utils_split_bonus.c\
bonus/pipex_utils2_bonus.c\
bonus/here_doc.c\
bonus/get_next_line.c\
bonus/get_next_line_utils.c\
bonus/pipex_bonus_strchr.c\

HEADER = pipex.h

HEADERB = bonus/pipex_bonus.h\
bonus/get_next_line.h\

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)
$(NAME): $(OBJ)
	@cc $(FLAGS) $(OBJ) -o $@

%.o:%.c $(HEADER)
	@cc $(FLAGS) -c $< -o $@

clean:
	@rm -rf *.o bonus/*.o

bonus:
	@make OBJ="$(OBJB)" all

fclean: clean
	@rm -rf $(NAME) 

re: fclean $(NAME) 

rb: fclean bonus

.PHONY: all clean fclean bonus rb