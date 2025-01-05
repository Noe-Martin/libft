/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:38:42 by nmartin           #+#    #+#             */
/*   Updated: 2024/12/06 13:56:36 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_conv(const char *str, va_list lst, t_list **rlst)
{
	int	i;

	i = 1;
	i += is_bonus(str);
	if (str[i] == 'c')
		prnt_c(va_arg(lst, int), str, rlst);
	else if (str[i] == 's')
		prnt_s(va_arg(lst, char *), str, rlst);
	else if (str[i] == 'p')
		prnt_p(va_arg(lst, unsigned long long), str, rlst);
	else if (str[i] == 'd')
		prnt_i(va_arg(lst, int), str, rlst);
	else if (str[i] == 'i')
		prnt_i(va_arg(lst, int), str, rlst);
	else if (str[i] == 'u')
		prnt_u(va_arg(lst, unsigned int), str, rlst);
	else if (str[i] == 'x')
		prnt_x(va_arg(lst, unsigned int), 0, str, rlst);
	else if (str[i] == 'X')
		prnt_x(va_arg(lst, unsigned int), 1, str, rlst);
	else if (str[i] == '%')
		prnt_percent(rlst);
	i++;
	return (i);
}
