/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:14:29 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 16:11:00 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	print_flag(t_flags *flags, char c)
{
	int	len;

	len = 0;
	if (!flags->is_negative)
		len += ft_putchar(c);
	return (len);
}