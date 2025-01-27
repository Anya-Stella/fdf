/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:41:36 by tishihar          #+#    #+#             */
/*   Updated: 2025/01/23 19:44:04 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	put_pixel(int x, int y, t_fdf *data_)
{
	mlx_pixel_put(data_->mlx_ptr, data_->window_ptr, x, y, 0xffffff);
}
