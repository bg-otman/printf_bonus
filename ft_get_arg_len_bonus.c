/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_len_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:16:38 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 22:02:23 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	get_string_len(va_list args)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		return (ft_strlen("(null)"));
	len = ft_strlen(str);
	return (len);
}

int	get_arg_len(char specifier, va_list args)
{
	unsigned long long	ptr;

	if (specifier == 's')
		return (get_string_len(args));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_nbr_len(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_unsigned_nbr_len(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_hex_len(va_arg(args, unsigned int)));
	else if (specifier == 'p')
	{
		ptr = va_arg(args, unsigned long long);
		if (!ptr)
			return (ft_strlen("(nil)"));
		return (2 + ft_hex_len(ptr));
	}
	else if (specifier == 'c')
		return (1);
	return (-1);
}
