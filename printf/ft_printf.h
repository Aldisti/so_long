/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflibft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:33:39 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/23 16:22:13 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "../so_long.h"

int		ft_printf(const char *str, ...);
int		ft_switch(const char chr, va_list *arg);
void	*ft_calloc(size_t num, size_t dim);
char	*ft_itoa(long n);
int		ft_reverse(const char *str);
int		ft_nlen(long n);
int		ft_abs(int n);
int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_putinbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_putnbr_base(unsigned int n, int type);
int		ft_putlnbr(unsigned long long n);

#endif
