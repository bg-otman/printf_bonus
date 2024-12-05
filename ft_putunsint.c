/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:10:52 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 16:15:49 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_putunsint(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putunsint(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
