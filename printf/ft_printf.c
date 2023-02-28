/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:06:07 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/23 15:19:36 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_switch(const char chr, va_list *arg)
{
	if (chr == 'c')
		return (ft_putchar(va_arg(*arg, int)));
	else if (chr == 's')
		return (ft_putstr(va_arg(*arg, char *)));
	else if (chr == 'p')
		return (ft_putstr("0x") + ft_putlnbr(va_arg(*arg, unsigned long long)));
	else if (chr == 'd' || chr == 'i')
		return (ft_putinbr(va_arg(*arg, int)) - 1);
	else if (chr == 'u')
		return (ft_putunbr(va_arg(*arg, unsigned int)) - 1);
	else if (chr == 'x')
		return (ft_putnbr_base(va_arg(*arg, int), 1));
	else if (chr == 'X')
		return (ft_putnbr_base(va_arg(*arg, int), 0));
	else if (chr == '%')
		return (ft_putchar(37));
	else
		return (ft_putchar(chr));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	count;
	int		i;

	count = 0;
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == 37)
			count += ft_switch(str[++i], &args);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

void	*ft_calloc(size_t num, size_t dim)
{
	char	*ptr;
	size_t	i;

	if (num >= 1247483424)
		return (0);
	ptr = (char *) malloc (num * dim);
	if (!ptr)
		return (0);
	i = 0;
	while (i < (num * dim))
		ptr[i++] = 0;
	return ((void *)ptr);
}

int	ft_reverse(const char *s)
{
	int	i;

	i = ft_strlen((char *)s);
	while (--i >= 0)
		ft_putchar(s[i]);
	return (ft_strlen((char *)s));
}
