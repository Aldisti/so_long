/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:00:47 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/23 15:18:33 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buff[1 + 1];
	char		*str;
	int			r;

	if (fd < 0)
		return (0);
	if (!(*buff))
		r = read(fd, buff, 1);
	else
		r = ft_strlen(buff);
	str = ft_get_first_str(buff);
	while (r && !ft_nlinstr(str))
	{
		if (r <= 0)
			break ;
		if (!(*buff))
			r = read(fd, buff, 1);
		if (r <= 0)
			break ;
		str = ft_realloc(str, buff);
	}
	if (str && *str)
		return (str);
	free(str);
	return (0);
}
/*
int	main(void)
{
	char	*ptr;
	int		file;
	int		i;

	i = 11;
	file = open("test", O_RDONLY);
	while (i-- > 0)
	{
		ptr = get_next_line(file);
		if (!ptr || !*ptr)
			break ;
		printf("|%s", ptr);
		free(ptr);
	}
	close(file);
	return (0);
}
*/
