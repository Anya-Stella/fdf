/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:59:32 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/20 13:31:00 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// include
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

typedef struct s_fdf
{
	int	width;
	int	height;

	int	**matrix;
} t_fdf;


// init_data
bool	set_height(char *file_name, int *height);
bool	set_width(char *file_name, int *width);
bool	set_matrix(char *file_name, t_fdf *data_);
void	init_data(t_fdf *data_);
void	set_data(char *file_name, t_fdf *data_);

// main
int	main();

// test
void printZ(int **matrix, int height, int width);

#endif