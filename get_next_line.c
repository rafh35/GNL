/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 08:49:10 by maberkan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 15:13:33 by maberkan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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

	str = read_line(str, fd);
	if (fd < 1 || line == NULL)
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (0);
	i = 0;
	while (str && str[i] != '\n' && ++i)
	{
		if (str[i] == '\n')
		{
			*line = ft_strsub(str, 0, i);
			str = ft_strsub(str, i + 1, ft_strlen(str) - i);
			return (1);
		}
		*line = ft_strsub(str, 0, ft_strlen(str) - i);
	}
	return (0);
}
