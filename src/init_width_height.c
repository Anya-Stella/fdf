/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_width_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:26:29 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/22 19:19:13 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// str上の要素の数
static	bool	is_delim(char c)
{
	return (c == ' ' || c == '-' || c == '\n');
}

static	int	count_words(char *str, bool (*is_delim)(char c))
{
	int	count;

	if (!str)
		return (-1);
	count = 0;
	while (*str)
	{
		if (*str && is_delim(*str))
			str++;
		else
		{
			if (count == INT_MAX)
				return (-1);
			count++;
			while (*str && !is_delim(*str))
				str++;
		}
	}
	return (count);
}

// fdの示すFDFファイルの横幅を返す。エラーの場合は−１を返す。
static	int	caluculate_width(int fd)
{
	char	*line;
	int		width_origin;
	int		width_temp;

	line = get_next_line(fd);
	width_origin = count_words(line, is_delim);
	if (width_origin <= 0)
	{
		if (line)
			free(line);
		return (-1);
	}
	while (line)
	{
		width_temp = count_words(line, is_delim);
		free(line);
		if (width_origin != width_temp)
			return (-1);
		line = get_next_line(fd);
	}
	return (width_origin);
}

bool	set_height(char *file_name, int *height)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	*height = count;
	close(fd);
	return (true);
}

bool	set_width(char *file_name, int *width)
{
	int		fd;
	int		width_temp;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (false);
	width_temp = caluculate_width(fd);
	if (width_temp <= 0)
	{
		close(fd);
		return (false);
	}
	*width = width_temp;
	close(fd);
	return (true);
}
