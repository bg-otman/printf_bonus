/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_minus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:36:08 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 15:55:32 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	handle_minus(t_flags *flags, va_list args)
{
	int	len;

	len = 0;
	if (!flags->dash)
		len = check_specifier(flags->specifier, args);
	while (len < flags->width)
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}
