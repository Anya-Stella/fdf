/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:59:32 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/29 21:37:49 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// include
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>

typedef struct s_fdf
{
	int	width;
	int	height;
	int	**matrix;

	int zoom;
	int	z_zoom;
	
	void *mlx_ptr;
	void *window_ptr;
} t_fdf;

typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_line
{
	int x0;
	int y0;
	int x1;
	int y1;

	int	dx;
	int dy;

	int color;
} t_line;


// init_data
bool	set_height(char *file_name, int *height);
bool	set_width(char *file_name, int *width);
bool	set_matrix(char *file_name, t_fdf *data_);
bool	validation_and_set_data(char *file_name, t_fdf *data_);
void	init_data(t_fdf *data_);
void	set_mlx(t_fdf *data_, int width, int height, char *title);

// draw
void	draw_line(t_point *p0_, t_point *p1_, t_fdf *data_);
void	draw_grid(t_fdf *data_);

// clean
void	vacuum_matrix(int **matrix);

// main
int	main();

// test
void print_z(int **matrix, int height, int width);

// utils
void	put_pixel(int x, int y, int color, t_fdf *data_);
int	zoom(int value, int magnification);
int	caluculate_isometric_x(int x, int y);
int	caluculate_isometric_y(int x, int y, int z);


#endif