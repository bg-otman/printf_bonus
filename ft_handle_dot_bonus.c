/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_dot_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:18:56 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 20:47:35 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static	int	unsigned_precision(va_list args, int precision, t_flags *flags)
{
	unsigned int	num;
	int				len;

	len = 0;
	num = va_arg(args, unsigned int);
	if (flags->width > flags->precision && !flags->minus)
	{
		len += print_n(' ', flags->width - flags->precision);
	}
	while (precision > ft_unsigned_nbr_len(num))
	{
		len += ft_putchar('0');
		precision--;
	}
	len += ft_putunsint(num);
	return (len);
}

static	int	handle_null_string(int precision, t_flags *flags)
{
	int	len;
	int	spaces;

	len = 0;
	spaces = 0;
	if (precision < 6)
	{
		if (!flags->minus && !flags->zero)
			spaces += print_n(' ', flags->width);
		if (flags->minus)
			spaces += print_n(' ', flags->width);
		return (spaces);
	}
	if (flags->minus)
		len += write(1, "(null)", 6);
	if (!flags->minus && !flags->zero)
		spaces += print_n(' ', flags->width - 6);
	if (!flags->minus)
		len += write(1, "(null)", 6);
	if (flags->minus)
		spaces += print_n(' ', flags->width - 6);
	return (len + spaces);
}

static	int	string_precision(va_list args, int precision, t_flags *flags)
{
	char	*buffer;
	int		len;
	int		spaces;
	int		i;
	int		print_len;

	buffer = va_arg(args, char *);
	if (buffer == NULL)
		return (handle_null_string(precision, flags));
	len = ft_strlen(buffer);
	print_len = len;
	if (precision < len)
		print_len = precision;
	spaces = 0;
	if (!flags->minus)
		spaces += print_n(' ', flags->width - print_len);
	i = 0;
	while (i < print_len)
		ft_putchar(buffer[i++]);
	if (flags->minus)
		spaces += print_n(' ', flags->width - print_len);
	return (spaces + print_len);
}

static	int	hex_precision(va_list args, int pr, char *hex, t_flags *flags)
{
	unsigned int	nb;
	int				len;
	int				hex_len;

	len = 0;
	nb = va_arg(args, unsigned int);
	hex_len = ft_hex_len(nb);
	if (hex_len > pr)
		pr = hex_len;
	if (flags->width > pr && !flags->minus)
	{
		len += print_n(' ', flags->width - pr);
	}
	while (pr > hex_len)
	{
		len += ft_putchar('0');
		pr--;
	}
	len += ft_puthex(nb, hex);
	if (flags->minus)
		len += print_n(' ', flags->width - len);
	return (len);
}

int	handle_dot(t_flags *flags, va_list args)
{
	int	precision;

	precision = flags->precision;
	if (flags->specifier == 'd' || flags->specifier == 'i')
		return (decimal_precision(args, precision, flags));
	else if (flags->specifier == 's')
		return (string_precision(args, precision, flags));
	else if (flags->specifier == 'u')
		return (unsigned_precision(args, precision, flags));
	else if (flags->specifier == 'x')
		return (hex_precision(args, precision, "0123456789abcdef", flags));
	else if (flags->specifier == 'X')
		return (hex_precision(args, precision, "0123456789ABCDEF", flags));
	return (ft_putchar('%'));
}
