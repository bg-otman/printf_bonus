/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:52:20 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 16:13:00 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static	int	handle_percent(const char *str, int *i, va_list args)
{
	int	temp;
	int	len;

	temp = handle_format(&str[*i + 1], args);
	if (temp == -1)
		return (-1);
	len = temp;
	(*i)++;
	while (is_valid_flag(str[*i]) || is_valid_specifier(str[*i])
		|| ft_isdigit(str[*i]))
		(*i)++;
	return (len);
}

static	int	handle_character(const char *str, int *i)
{
	int	len;

	len = ft_putchar(str[*i]);
	(*i)++;
	return (len);
}

static	int	process_format(const char *str, int *i, va_list args)
{
	int	temp;

	if (str[*i] == '%')
	{
		temp = handle_percent(str, i, args);
		if (temp == -1)
			return (-1);
		return (temp);
	}
	else
		return (handle_character(str, i));
}

static	int	process_string(const char *str, int *i, va_list args, int *printlen)
{
	int	temp;

	temp = process_format(str, i, args);
	if (temp == -1)
		return (-1);
	*printlen += temp;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		printlen;
	int		i;
	va_list	args;
	int		temp;

	if (!str)
		return (-1);
	va_start(args, str);
	printlen = 0;
	i = 0;
	temp = 0;
	while (str[i])
	{
		temp = process_string(str, &i, args, &printlen);
		if (temp == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (printlen);
}
