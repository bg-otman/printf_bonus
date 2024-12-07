/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_zero_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:34:45 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 20:47:54 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

void	print_positive(char specifier, va_list args)
{
	int	num;

	num = 0;
	if (specifier == 'd' || specifier == 'i')
	{
		num = va_arg(args, int);
		if (num == -2147483648)
			ft_putstr("2147483648");
		else
		{
			num = -num;
			ft_putnbr(num);
		}
	}
}

static	int	print_zero(int is_negative, int width, int len)
{
	if (is_negative)
		ft_putchar('-');
	while (len < width)
		len += ft_putchar('0');
	return (len);
}

int	handle_zero(t_flags *flags, va_list args)
{
	int	len;
	int	plus;

	len = 0;
	plus = 0;
	len = get_len(flags->specifier, args);
	if (len == -1)
		return (-1);
	if (flags->plus)
		plus = print_flag(flags, '+');
	len = print_zero(flags->is_negative, flags->width, len);
	len += plus;
	if (flags->is_negative)
		print_positive(flags->specifier, args);
	else
		check_specifier(flags->specifier, args);
	return (len);
}
