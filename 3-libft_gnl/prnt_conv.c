/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:38:42 by nmartin           #+#    #+#             */
/*   Updated: 2025/01/05 12:21:58 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ftp_printf_conv(const char *str, va_list lst, t_list **rlst)
{
	int	i;

	i = 1;
	i += ftp_is_bonus(str);
	if (str[i] == 'c')
		ftp_c(va_arg(lst, int), str, rlst);
	else if (str[i] == 's')
		ftp_s(va_arg(lst, char *), str, rlst);
	else if (str[i] == 'p')
		ftp_p(va_arg(lst, unsigned long long), str, rlst);
	else if (str[i] == 'd')
		ftp_i(va_arg(lst, int), str, rlst);
	else if (str[i] == 'i')
		ftp_i(va_arg(lst, int), str, rlst);
	else if (str[i] == 'u')
		ftp_u(va_arg(lst, unsigned int), str, rlst);
	else if (str[i] == 'x')
		ftp_x(va_arg(lst, unsigned int), 0, str, rlst);
	else if (str[i] == 'X')
		ftp_x(va_arg(lst, unsigned int), 1, str, rlst);
	else if (str[i] == '%')
		ftp_percent(rlst);
	i++;
	return (i);
}
