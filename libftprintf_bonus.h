/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:14:01 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 16:27:42 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
	int		zero;
	int		minus;
	int		plus;
	int		is_negative;
	int		space;
	int		dash;
	int		width;
	int		precision;
	int		has_precision;
	char	specifier;
}	t_flags;

int		ft_printf(const char *str, ...);
int		check_specifier(char c, va_list args);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_isdigit(int c);
int		ft_puthex(unsigned int nb, char *hex);
int		ft_putadresse(unsigned long long nb);
int		ft_putunsint(unsigned int nb);
int		is_valid_specifier(char c);
long	ft_atoi(const char *str);
int		ft_nbr_len(int nb);
int		is_valid_flag(char c);
int		get_arg_len(char specifier, va_list args);
size_t	ft_strlen(const char *s);
int		handle_flags(const char *str, va_list args);
int		handle_format(const char *str, va_list args);
int		ft_hex_len(unsigned long n);
int		handle_dot(t_flags *flags, va_list args);
int		ft_unsigned_nbr_len(unsigned int nb);
int		handle_width(t_flags *flags, va_list args);
int		ft_handle_priority(t_flags *flags, va_list args, int has_p);
int		handle_zero(t_flags *flags, va_list args);
int		handle_minus(t_flags *flags, va_list args);
int		get_len(char specifier, va_list args);
int		print_flag(t_flags *flags, char c);
int		print_n(char c, int n);
int		check_null(char c, va_list args);
int		handle_dash(t_flags *flags, char specifier, va_list args);
int		handle_dash_and_dot(t_flags *flags, va_list args);
int		handle_minus(t_flags *flags, va_list args);
int		decimal_precision(va_list args, int precision, t_flags *flags);
void	intialize_flags(t_flags *flags);

#endif
