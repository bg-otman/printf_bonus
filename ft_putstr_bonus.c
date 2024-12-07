/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:52:48 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 20:49:31 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		count += write(1, "(null)", 6);
	else
	{
		while (*s)
		{
			count += write(1, s, 1);
			s++;
		}
	}
	return (count);
}
