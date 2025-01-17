/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_project.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:47:13 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/17 20:06:18 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"







void	init_data(t_fdf *data_)
{
	data_->height = 0;
	data_->width = 0;
	data_->matrix = NULL;
}


// void	fill_column(char *line, int *col)
// {
// 	int	*arr;
// 	int	*temp;
// 	int	*temp2;

// 	arr = ft_split(line, " ");// ""123", "45564", "8475", ..."
// 	if (!arr)
// 		return ;
// 	temp = arr;
// 	temp2 = arr;
// 	while (*temp)
// 	{
// 		*col = ft_atoi(temp);
// 		col++;
// 		temp++;
// 	}
// 	while (*temp2)
// 	{
// 		free(*temp2);
// 		temp2++;
// 	}
// 	free(arr);
// }


void	set_data(char *file_name, t_fdf *data_)
{

	// init w/h
	set_height(file_name, &(data_->height));
	set_width(file_name, &(data_->width));





}
