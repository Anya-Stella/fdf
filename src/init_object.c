/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:47:13 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/17 12:25:19 by tishihar         ###   ########.fr       */
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

static	bool	set_height(char *file_name, int *height)
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

static	bool	set_width(char *file_name, int *width)
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

void	init_data(t_fdf *data_)
{
	data_->height = 0;
	data_->width = 0;
	data_->matrix = NULL;
}

void	init_matrix(char *file_name, t_fdf *data_)
{
	int	width;
	int	height;
	(void) *data_;

	// get_height
	set_height(file_name, &height);

	// get_width
	set_width(file_name, &width);


	//set_matrix
	printf("width: %d",width);
	printf("height: %d",height);

}
