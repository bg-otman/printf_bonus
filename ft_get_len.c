/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:10:46 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 15:45:47 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	get_len(char specifier, va_list args)
{
	va_list	args_copy;
	int		len;

	va_copy(args_copy, args);
	len = get_arg_len(specifier, args_copy);
	va_end(args_copy);
	return (len);
}
