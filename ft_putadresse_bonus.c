/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadresse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:12:06 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 20:48:46 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static	int	ft_getadresse(unsigned long long nb, char *hex)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_getadresse(nb / 16, hex);
	count += ft_putchar(hex[nb % 16]);
	return (count);
}

int	ft_putadresse(unsigned long long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += ft_getadresse(nb, "0123456789abcdef");
	}
	return (count);
}