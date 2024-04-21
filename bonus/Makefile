CC = cc 
RM = rm -rf 
CFLAGS = -Wall -Wextra -Werror 
NAME = checker
BHEADER = ./push_swap_bonus.h


BSRCS = ./main_bonus.c  ./linkedlist/linkedlist_bonus.c ./utils/ft_exit_bonus.c ./utils/ft_free_bonus.c ./utils/ft_checks_bonus.c ./utils/split_w_bonus.c ./validate/sign_dup_bonus.c ./handler_bonus.c ./linkedlist/linkedlist_clear_bonus.c ./linkedlist/linkedlist_search_bonus.c ./moves/helpers_moves_bonus.c  ./moves/ft_moves_bonus.c ./validate/ft_validate_bonus.c 

B_OBJS = $(BSRCS:.c=.o) 

all : ../$(NAME)


../$(NAME) : $(B_OBJS)
	@make -C ../libft/
	$(CC) $(CFLAGS) $(B_OBJS) ../libft/libft.a -o ../$(NAME)

%.o : %.c $(BHEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	@$(RM) $(B_OBJS)

fclean : clean
	@$(RM) ../$(NAME)


.PHONY : all fclean clean 