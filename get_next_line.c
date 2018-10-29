/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 08:49:10 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 11:20:54 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*read_line(char *str, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		nbr_oct;

	while ((nbr_oct = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbr_oct] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	static char	*str;

	if (!str)
	{
		str = ft_strnew(0);
		str = read_line(str, fd);
	}
	if (fd < 0 || line == NULL || read(fd, *line, 0) < 0)
		return (-1);
	i = 0;
	while (str[i])
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n' || str[i] == '\0')
		{
			*line = ft_strsub(str, 0, i);
			str = ft_strsub(str, i + 1, ft_strlen(str) - i);
			return (1);
		}
	}
	*line = NULL;
	return (0);
}
