/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intialize_flags_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:35:53 by obouizi           #+#    #+#             */
/*   Updated: 2024/12/05 20:48:02 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

void	intialize_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->is_negative = 0;
	flags->space = 0;
	flags->dash = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->has_precision = 0;
	flags->specifier = '%';
}
