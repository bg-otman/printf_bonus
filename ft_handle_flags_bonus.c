/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:16:56 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/06 09:22:39 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static	void	set_flags(const char *str, int *i, t_flags *flags)
{
	while (str[*i] && !(str[*i] >= '1' && str[*i] <= '9')
		&& !is_valid_specifier(str[*i]))
	{
		if (str[*i] == '-')
			flags->minus = 1;
		if (str[*i] == '+')
			flags->plus = 1;
		if (str[*i] == ' ')
			flags->space = 1;
		if (str[*i] == '0')
			flags->zero = 1;
		if (str[*i] == '#')
			flags->dash = 1;
		if (str[*i] == '.')
			flags->has_precision = 1;
		(*i)++;
	}
}

static	void	set_width_or_precision(const char *str, int *i, t_flags *flags)
{
	if (ft_isdigit(str[*i]))
	{
		if (flags->has_precision)
			flags->precision = ft_atoi(&str[*i]);
		else
			flags->width = ft_atoi(&str[*i]);
		while (ft_isdigit(str[*i]))
			(*i)++;
	}
}

static	void	set_precision(const char *str, int *i, t_flags *flags)
{
	if (str[*i] == '.')
	{
		flags->has_precision = 1;
		(*i)++;
		if (ft_isdigit(str[*i]))
		{
			flags->precision = ft_atoi(&str[*i]);
			while (ft_isdigit(str[*i]))
				(*i)++;
		}
	}
}

void	parse_flags(const char *str, t_flags *flags, va_list args)
{
	int		i;
	int		num;
	va_list	args_copy;

	i = 0;
	set_flags(str, &i, flags);
	set_width_or_precision(str, &i, flags);
	set_precision(str, &i, flags);
	if (is_valid_specifier(str[i]))
		flags->specifier = str[i];
	if (flags->specifier == 'd' || flags->specifier == 'i')
	{
		va_copy(args_copy, args);
		num = va_arg(args_copy, int);
		if (num < 0)
			flags->is_negative = 1;
		va_end(args_copy);
	}
}

int	handle_flags(const char *str, va_list args)
{
	t_flags	flags;

	intialize_flags(&flags);
	parse_flags(str, &flags, args);
	if (flags.width == -1 || flags.precision == -1)
		return (-1);
	return (ft_handle_priority(&flags, args, flags.has_precision));
}
