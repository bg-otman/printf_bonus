/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_priority_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:04:47 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/06 09:54:37 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	space_flag(t_flags *flags, va_list args)
{
	int	len;

	len = 0;
	if (!flags->minus && !flags->zero && !flags->has_precision
		&& flags->width == 0)
	{
		len += print_flag(flags, ' ');
		len += check_specifier(flags->specifier, args);
	}
	else
		len += print_flag(flags, ' ');
	return (len);
}

int	dash_flag(t_flags *flags, va_list args)
{
	int	len;

	len = 0;
	if (flags->width > 0 && !flags->minus && !flags->zero)
	{
		flags->width -= get_len(flags->specifier, args);
		if (!flags->minus && !flags->zero && flags->width > 0)
		{
			flags->width -= 2;
			while (len < flags->width)
				len += ft_putchar(' ');
		}
	}
	len += handle_dash(flags, flags->specifier, args);
	if (flags->minus)
	{
		while (len < flags->width)
			len += ft_putchar(' ');
	}
	return (len);
}

int	handle_plus_priority(t_flags *flags, va_list args)
{
	int	len;

	len = 0;
	if (!flags->minus && !flags->has_precision
		&& !flags->zero && flags->width == 0)
	{
		len += print_flag(flags, '+');
		len += check_specifier(flags->specifier, args);
	}
	else if (flags->minus || flags->zero)
	{
		if (flags->minus && !flags->dash && !flags->has_precision)
		{
			len += print_flag(flags, '+');
			len += handle_minus(flags, args);
		}
		else if (flags->zero && !flags->dash && !flags->has_precision)
			len += handle_zero(flags, args);
	}
	return (len);
}

int	handle_precision_priority(t_flags *f, va_list args)
{
	int	len;

	len = 0;
	if (f->plus && f->minus)
		len += print_flag(f, '+');
	if (!f->precision && f->width && !check_null(f->specifier, args))
	{
		if (f->minus)
			len += handle_minus(f, args);
		else if (f->dash)
			len += handle_dash(f, f->specifier, args);
		else
			len += handle_width(f, args);
	}
	else if (!f->precision && check_null(f->specifier, args))
	{
		if (f->width > 0)
		{
			while (len < f->width)
				len += ft_putchar(' ');
		}
	}
	else
		len += handle_dot(f, args);
	return (len);
}

int	ft_handle_priority(t_flags *f, va_list args, int has_p)
{
	int	len;

	len = 0;
	if (((f->plus || f->space) && !f->is_negative) && (f->width > 0))
		f->width--;
	if (f->dash && check_null(f->specifier, args) && has_p)
		f->width += 2;
	if (f->minus && !f->plus && !has_p && !f->space && !f->zero && !f->dash)
		len += handle_minus(f, args);
	if (f->zero && !f->minus && !f->plus && !has_p && !f->space && !f->dash)
		len += handle_zero(f, args);
	if (f->space && !f->plus)
		len += space_flag(f, args);
	if (f->dash && !has_p)
		len += handle_dash(f, f->specifier, args);
	if (f->plus)
		len += handle_plus_priority(f, args);
	if (f->width > 0 && !f->minus && !f->zero && !f->dash && !has_p)
		len += handle_width(f, args);
	if (f->dash && has_p)
		len += handle_dash_and_dot(f, args);
	else if (has_p)
		len += handle_precision_priority(f, args);
	return (len);
}
