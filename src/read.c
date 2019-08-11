/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:49:11 by bdeomin           #+#    #+#             */
/*   Updated: 2019/04/18 19:34:09 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	whitespace(char *str, int *i, int *len)
{
	while (str[*i] == ' ')
		*i = *i + 1;
	if (str[*i] != '\0')
		*len = *len + 1;
	*i = *i - 1;
}

int		count_tab(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			whitespace(str, &i, &len);
		i++;
	}
	return (len);
}

int		one_check(int fd, t_map **map)
{
	char *str;

	if (get_next_line(fd, &str) == 1)
	{
		if (search_other_chars(str))
		{
			free(str);
			return (1);
		}
		(*map)->len_vertical++;
		(*map)->len_horizontal = count_tab(str);
		free(str);
	}
	else
	{
		show_error();
	}
	return (0);
}

int		first_read(int fd, t_map **map)
{
	char	*str;

	if (one_check(fd, &(*map)))
		return (1);
	while (get_next_line(fd, &str) == 1)
	{
		if (search_other_chars(str))
		{
			free(str);
			return (1);
		}
		((*map)->len_vertical)++;
		if ((*map)->len_horizontal != count_tab(str))
		{
			free(str);
			return (1);
		}
		free(str);
	}
	return (0);
}

void	reading_file(int fd, t_map **map)
{
	char	*str;
	char	**ptr;
	int		i;
	int		j;

	i = 0;
	while (get_next_line(fd, &str) == 1)
	{
		j = -1;
		ptr = ft_strsplit(str, ' ');
		while (++j < (*map)->len_horizontal)
		{
			(*map)->points[i][j].z = ft_atoi(ptr[j]) * -1;
			free(ptr[j]);
		}
		i++;
		free(ptr);
		free(str);
	}
}
