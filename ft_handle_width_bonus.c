/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_width_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:09:09 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 20:47:51 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	handle_width(t_flags *flags, va_list args)
{
	int	len;

	len = 0;
	if (flags->width == -1)
		return (-1);
	len = get_len(flags->specifier, args);
	if (len == -1)
		return (-1);
	while (len < flags->width)
	{
		ft_putchar(' ');
		len++;
	}
	if (flags->plus)
		len += print_flag(flags, '+');
	check_specifier(flags->specifier, args);
	return (len);
}
