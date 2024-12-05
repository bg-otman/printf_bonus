/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:21:46 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 15:28:53 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	check_null(char c, va_list args)
{
	va_list	args_copy;
	int		is_null;

	is_null = 0;
	va_copy(args_copy, args);
	if (c == 's' && !va_arg(args_copy, char *))
		is_null = 1;
	else if ((c == 'd' || c == 'i') && !va_arg(args_copy, int))
		is_null = 1;
	else if (c == 'c' && !va_arg(args_copy, int))
		is_null = 1;
	else if ((c == 'x' || c == 'X') && !va_arg(args_copy, unsigned int))
		is_null = 1;
	else if (c == 'u' && !va_arg(args_copy, unsigned int))
		is_null = 1;
	else if (c == 'p' && !va_arg(args_copy, unsigned long long))
		is_null = 1;
	va_end(args_copy);
	return (is_null);
}
