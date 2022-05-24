/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:55:49 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/22 12:31:26 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	render_pixel_put(t_img *img, int x, int y, int color)
{
	int		i;
	char	*pixel;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while(j < WIN_WIDTH)
			render_pixel_put(img, j++, i, color);
		++i;
	}
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.pos.y;
	while (i < rect.pos.y + rect.height)
	{
		j = rect.pos.x;
		while (j < rect.pos.x + rect.width)
			render_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (e_none);
}

int	render(t_game *game)
{
	if (game->win_ptr == NULL)
		kill_program(game, e_window_null);
	render_background(&game->img, WHITE_PIXEL);
	render_rect(&game->img, (t_rect)
	{
		(t_vector2)
	{
		WIN_WIDTH - 100,
		WIN_HEIGHT - 100
	},
		100,
		100,
		GREEN_PIXEL
	});
	render_rect(&game->img, game->player.rect);
	//printf("Rendering");
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, 0, 0);
	return (e_none);
}
