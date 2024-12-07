SRCS = ft_putchar.c ft_check_specifier.c ft_strlen.c ft_printf.c ft_valid_specifier.c ft_putstr.c ft_putnbr.c ft_puthex.c ft_putunsint.c ft_putadresse.c
SRCS_BONUS = ft_printf_bonus.c ft_putchar_bonus.c ft_valid_flag_bonus.c ft_print_n_bonus.c ft_intialize_flags_bonus.c \
			 ft_decimal_precision_bonus.c ft_handle_zero_bonus.c ft_handle_minus_bonus.c ft_check_null_bonus.c \
			 ft_handle_width_bonus.c ft_get_len_bonus.c ft_print_flag_bonus.c ft_isdigit_bonus.c ft_hex_len_bonus.c \
			 ft_handle_priority_bonus.c ft_handle_dash_dot_bonus.c ft_handle_dash_bonus.c ft_unsigned_nbr_len_bonus.c \
			 ft_check_specifier_bonus.c ft_handle_format_bonus.c ft_handle_dot_bonus.c ft_handle_flags_bonus.c \
			 ft_strlen_bonus.c ft_get_arg_len_bonus.c ft_nbr_len_bonus.c ft_valid_specifier_bonus.c ft_putstr_bonus.c \
			 ft_atoi_bonus.c ft_putnbr_bonus.c ft_puthex_bonus.c ft_putunsint_bonus.c ft_putadresse_bonus.c
OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

bonus : $(OBJECTS_BONUS)
	$(AR) $(NAME) $(OBJECTS_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
.SECONDARY : $(OBJECTS) $(OBJECTS_BONUS)