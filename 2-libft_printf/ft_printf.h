/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmartin <nmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:59:24 by nmartin           #+#    #+#             */
/*   Updated: 2025/01/02 15:26:13 by nmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# ifndef FD
#  define FD 1
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

void	c_null(const char *bns, t_list **rlst);
void	put_spaces(int is_minus, t_list **rlst, char *width);
void	str_error(t_list **rlst);
void	del(void *content);

char	*b_str_dot(const char *bns, char *str, int null);
int		b_dot_b(const char *str);
char	*b_is_dot_nb(const char *bns, char *str, int is_zero);
int		is_bonus(const char *str);
int		b_check(char c, const char *str);
int		b_check_d(const char *str);
char	*b_is_digit(const char *bns, char *str);
int		b_digit(const char *bns);
int		is_hashtag(const char *bns);
void	b_hashtag(const char *bns, char *str, unsigned int nb);
char	*b_is_zero(const char *bns, char *str, int dot);

int		ft_printf(const char *str, ...);
void	check_char(const char *str, va_list lst, t_list **rlst);
int		ft_printf_conv(const char *str, va_list lst, t_list **rlst);

int		hex_len(unsigned long long nbr);
int		int_len(long long nb);
int		hex_p(char *str, unsigned long long nb, int is_bonus, t_list **rlst);
void	nbr_p(char *str, long long nb, int bn);
void	str_upper(char *str);

void	prnt_c(char c, const char *bns, t_list **rlst);
void	prnt_s(char *str, const char *bns, t_list **rlst);
void	prnt_p(unsigned long long ptr, const char *bns, t_list **rlst);
void	prnt_i(int nb, const char *bns, t_list **rlst);
void	prnt_x(unsigned long long nb, int up, const char *bns, t_list **rlst);
void	prnt_u(unsigned int nb, const char *bns, t_list **rlst);
void	prnt_percent(t_list **rlst);

#endif
