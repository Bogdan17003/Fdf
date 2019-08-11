/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:15:44 by bdeomin           #+#    #+#             */
/*   Updated: 2019/01/17 16:15:47 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	read_file(char *buffer, int reading, char **str, int fd)
{
	char		*temp;

	buffer[reading] = '\0';
	if (str[fd] == NULL)
		str[fd] = ft_memalloc(1);
	temp = ft_strjoin(str[fd], buffer);
	free(str[fd]);
	str[fd] = temp;
}

void	check_end(char **line, char **str, int fd, int len)
{
	char	*temp;

	*line = ft_strsub(str[fd], 0, len);
	temp = ft_strdup(str[fd] + len + 1);
	free(str[fd]);
	str[fd] = temp;
	if (str[fd][0] == '\0')
		ft_strdel(&str[fd]);
}

int		newline(char **str, char **line, int fd, int reading)
{
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
		check_end(line, str, fd, len);
	else if (str[fd][len] == '\0')
	{
		if (reading == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[4864];
	int			reading;
	char		buffer[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((reading = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		read_file(buffer, reading, str, fd);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (reading < 0)
		return (-1);
	else if (reading == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (newline(str, line, fd, reading));
}
