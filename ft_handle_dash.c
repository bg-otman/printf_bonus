/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_dash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:16:49 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 15:51:01 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	print_prefix(char c)
{
	if (c == 'x')
		return (ft_putstr("0x"));
	else
		return (ft_putstr("0X"));
}

int	handle_non_zero(t_flags *flags, char *hex, char c, unsigned int nb)
{
	int	len;

	len = 0;
	if (!flags->minus && !flags->zero)
	{
		flags->width -= ft_hex_len(nb);
		while (len < flags->width - 2)
			len += ft_putchar(' ');
	}
	len += print_prefix(c);
	if (flags->zero && !flags->minus)
	{
		flags->width -= ft_hex_len(nb);
		while (len < flags->width)
			len += ft_putchar('0');
	}
	len += ft_puthex(nb, hex);
	if (flags->minus)
	{
		while (len < flags->width)
			len += ft_putchar(' ');
	}
	return (len);
}

static	int	hex_precision(t_flags *flags, va_list args, char *hex, char c)
{
	unsigned int	nb;
	int				len;

	len = 0;
	nb = va_arg(args, unsigned int);
	if (nb != 0)
		len = handle_non_zero(flags, hex, c, nb);
	else
	{
		if (flags->zero && !flags->minus)
			while (len < flags->width - 1)
				len += ft_putchar('0');
		if (!flags->minus && flags->width > 0)
			while (len < flags->width - 1)
				len += ft_putchar(' ');
		len += ft_putchar('0');
		if (flags->minus)
			while (len < flags->width)
				len += ft_putchar(' ');
	}
	return (len);
}

int	handle_dash(t_flags *flags, char specifier, va_list args)
{
	if (specifier == 'x')
		return (hex_precision(flags, args, "0123456789abcdef", 'x'));
	else if (specifier == 'X')
		return (hex_precision(flags, args, "0123456789ABCDEF", 'X'));
	else
		return (check_specifier(specifier, args));
}
