/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:59:32 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/23 18:49:00 by tishihar         ###   ########.fr       */
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

	void *mlx_ptr;
	void *window_ptr;
} t_fdf;


// init_data
bool	set_height(char *file_name, int *height);
bool	set_width(char *file_name, int *width);
bool	set_matrix(char *file_name, t_fdf *data_);
bool	validation_and_set_data(char *file_name, t_fdf *data_);
void	init_data(t_fdf *data_);
void	set_mlx(t_fdf *data_, int width, int height, char *title);

// draw
void	draw_line(t_fdf *data_);

// clean
void	vacuum_matrix(int **matrix);

// main
int	main();

// test
void print_z(int **matrix, int height, int width);

#endif