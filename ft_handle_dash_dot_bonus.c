/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_dash_dot_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:13:02 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 20:47:32 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	handle_width_padding(int width_padding)
{
	int	len;

	len = 0;
	while (width_padding-- > 0)
		len += ft_putchar(' ');
	return (len);
}

int	handle_precision_padding(int precision_padding)
{
	int	len;

	len = 0;
	while (precision_padding-- > 0)
		len += ft_putchar('0');
	return (len);
}

int	handle_dash_prefix(t_flags *flags, va_list args)
{
	int	len;

	len = 0;
	if (!check_null(flags->specifier, args))
	{
		if (flags->specifier == 'x')
			len += ft_putstr("0x");
		else if (flags->specifier == 'X')
			len += ft_putstr("0X");
	}
	return (len);
}

int	handle_dash_and_dot(t_flags *flags, va_list args)
{
	int	len;
	int	value_len;
	int	precision_padding;
	int	width_padding;

	len = 0;
	if (check_null(flags->specifier, args))
		value_len = 0;
	else
		value_len = get_len(flags->specifier, args);
	precision_padding = 0;
	if (flags->precision > value_len)
		precision_padding = flags->precision - value_len;
	width_padding = flags->width - (value_len + precision_padding + 2);
	if (width_padding < 0)
		width_padding = 0;
	if (!flags->minus)
		len += handle_width_padding(width_padding);
	len += handle_dash_prefix(flags, args);
	len += handle_precision_padding(precision_padding);
	if (!check_null(flags->specifier, args))
		len += check_specifier(flags->specifier, args);
	if (flags->minus)
		len += handle_width_padding(width_padding);
	return (len);
}
