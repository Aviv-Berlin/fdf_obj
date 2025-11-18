/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:40:55 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/26 11:40:59 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int		p_char(int c);
int		p_str(char *str);
int		p_pointer(void *ptr);
int		p_nbr(long n, char c, int counter);
int		sort_specifiers(va_list args, char c);
size_t	s_length(const char *s);
int		ft_printf(const char *format, ...);
int		p_address(long long n, char c, int counter);