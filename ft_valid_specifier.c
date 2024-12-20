/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:18:46 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 20:50:25 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	is_valid_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i'
		|| c == 'x' || c == 'X' || c == 'p' || c == 'u')
		return (1);
	return (0);
}
