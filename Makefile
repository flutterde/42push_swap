CC = cc 
RM = rm -rf 
CFLAGS = -Wall -Wextra -Werror 
NAME = push_swap
HEADER = ./mandatory/push_swap.h
SRCS = ./mandatory/main.c ./mandatory/utils/bs_helper.c ./mandatory/ft_sorting.c ./mandatory/linkedlist/linkedlist.c ./mandatory/utils/ft_exit.c ./mandatory/utils/ft_free.c ./mandatory/simple_sort.c ./mandatory/algo_calcul.c ./mandatory/utils/ft_checks.c ./mandatory/utils/sort_utils.c ./mandatory/utils/best_fr_utils.c ./mandatory/utils/split_w.c ./mandatory/validate/sign_dup.c ./mandatory/handler.c ./mandatory/linkedlist/linkedlist_clear.c ./mandatory/linkedlist/linkedlist_search.c ./mandatory/moves/helpers_moves.c  ./mandatory/moves/ft_moves.c ./mandatory/validate/ft_validate.c ./mandatory/best_friend.c 


OBJS = $(SRCS:.c=.o) 

all : $(NAME) 

$(NAME) : $(OBJS) $(HEADER)
	$(emo)
	@make -C libft/
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a  -o $(NAME)

bonus : 
	make -C bonus/


%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	@make clean -C libft/
	@$(RM) $(OBJS)
	@make clean -C bonus/

fclean : clean 
	@make fclean -C libft/
	@$(RM) $(NAME)
	@make fclean -C bonus/

re : fclean all 


.PHONY : all clean bonus fclean re 


define emo
@echo "\033[0;91m"
@echo "\t██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ "
@echo "\t██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗"
@echo "\t██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝"
@echo "\t██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ "
@echo "\t██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║   "
@echo "\t╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝ "
@echo "\033[0m"
@echo "\033[0;32m"
@echo "\t ______            _______         _                                  _ "
@echo "\t(____  \          (_______)       | |                            _   (_)"
@echo "\t ____)  ) _   _    _     _   ____ | |__    ___   _   _  _____  _| |_  _ "
@echo "\t|  __  ( | | | |  | |   | | / ___)|  _ \  / _ \ | | | |(____ |(_   _)| |"
@echo "\t| |__)  )| |_| |  | |___| |( (___ | | | || |_| || |_| |/ ___ |  | |_ | |"
@echo "\t|______/  \__  |   \_____/  \____)|_| |_| \___/ |____/ \_____|   \__)|_|"
@echo "\t         (____/   "
@echo "\033[0m"
@echo "\033[0;33m" 
@echo "\t  _ ____________    __  __ ___ ___  "
@echo "\t / |__ /__ /__  |  |  \/  | __|   \ "
@echo "\t | ||_ \|_ \ / /   | |\/| | _|| |) |"
@echo "\t |_|___/___//_/    |_|  |_|___|___/ "
@echo "\033[0m"
endef