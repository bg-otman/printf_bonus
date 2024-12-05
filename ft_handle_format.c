/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:17:08 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 15:55:10 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	handle_format(const char *str, va_list args)
{
	if (is_valid_specifier(*str))
		return (check_specifier(*str, args));
	else if (is_valid_flag(*str))
		return (handle_flags(str, args));
	else if (*str && *(str + 1) != '\0')
		return (ft_putchar('%'));
	return (0);
}
