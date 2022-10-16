NAME = push_swap

BONUSNAME = push_swap_bonus

CFLAGS = -Wall -Werror -Wextra  -g -fsanitize=address

SRC = 	push_swap.c controls.c count_arg.c define_array.c exit_push_swap.c libft_functions_two.c \
		libft_functions.c p_and_s_functions.c rotate_functions.c sort_array.c sort_functions.c \
		sort_calculate_step.c sort_index_array.c sort_for_small_five.c

BONUSSRC = push_swap_bonus.c controls_bonus.c count_arg_bonus.c define_array_bonus.c exit_push_swap_bonus.c \
		   libft_ft_bonus.c libft_func_bonus.c p_and_s_functions_bonus.c rotate_functions_bonus.c

OBJ = $(SRC:.c=.o)

BONUSOBJ = $(BONUSSRC:.c=.o)

all : $(NAME)

bonus : $(BONUSNAME)

$(NAME) : $(OBJ)
		gcc $(SRC) $(CFLAGS) -o $(NAME)

$(BONUSNAME) : $(BONUSOBJ)
		gcc $(BONUSSRC) $(CFLAGS) -o $(BONUSNAME)

clean : 
		rm -rf $(OBJ) $(NAME)

fclean :
		rm -rf $(OBJ) $(NAME) $(BONUSOBJ) $(BONUSNAME)

re : fclean all

.PHONY : clean fclean re all