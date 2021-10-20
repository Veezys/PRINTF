NAME	=	libftprintf.a

SRCS	=	ft_print_help.c	ft_print_symbol.c	ft_printf_untils.c\
			ft_printf.c		ft_print_help2.c\

HEADER	=	ft_printf.h
OBJ	=	$(SRCS:%.c=%.o)


CC	=	gcc

CCFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	: $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	@$(CC) $(CCFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@$(RM) $(NAME)

re		: fclean all
