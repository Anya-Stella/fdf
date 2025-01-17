/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_width_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:26:29 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/17 17:32:26 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	count_words(char *str, char c)
{
	char	**arr;
	char	**temp;
	char	**temp2;
	int		len;

	arr = ft_split(str, c);// ""123""467""
	if (!arr)
		return (0);
	len = 0;
	temp = arr;
	temp2 = arr;
	while (*(temp++))
		len++;
	// バキューム////////// 
	while (*temp2)
	{
		free(*temp2);
		temp2++;
	}
	free(arr);
	//////////////////
	return (len);
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
	while(!!(line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	*height = count;
	close(fd);
	return (true);
}

bool	set_width(char *file_name, int *width)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	*width = count_words(line, ' ');
	free(line);
	close(fd);
	return (true);
}

