/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:02:14 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 15:33:14 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static	int	handle_negative(int num, t_flags *flags)
{
	int	is_negative;

	is_negative = 0;
	if (num < 0)
	{
		flags->width--;
		is_negative = 1;
	}
	return (is_negative);
}

static	int	handle_precision(int precision, int num_len, int is_negative)
{
	if (precision < (num_len - is_negative))
		return (num_len - is_negative);
	return (precision);
}

static	int	print_sign(t_flags *flags, int *num)
{
	int	len;

	len = 0;
	if (*num < 0)
	{
		len += ft_putchar('-');
		if (*num != -2147483648)
			*num = -(*num);
	}
	if (flags->plus && !flags->minus)
		len += print_flag(flags, '+');
	return (len);
}

int	decimal_precision(va_list args, int precision, t_flags *flags)
{
	int	num;
	int	len;
	int	num_len;
	int	is_negative;

	len = 0;
	num = va_arg(args, int);
	num_len = ft_nbr_len(num);
	is_negative = handle_negative(num, flags);
	precision = handle_precision(precision, num_len, is_negative);
	if (flags->width > flags->precision && !flags->minus)
		len += print_n(' ', flags->width - precision);
	len += print_sign(flags, &num);
	while (precision > (num_len - is_negative))
	{
		len += ft_putchar('0');
		precision--;
	}
	if (num == -2147483648)
		len += ft_putstr("2147483648");
	else
		len += ft_putnbr(num);
	if (flags->minus)
		len += print_n(' ', flags->width - (len - is_negative));
	return (len);
}
