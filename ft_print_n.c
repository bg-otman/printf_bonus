/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:17:58 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 16:11:22 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	print_n(char c, int n)
{
	int	len;

	len = 0;
	while (len < n)
	{
		len += ft_putchar(c);
	}
	return (len);
}
