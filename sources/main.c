/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:21:42 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/22 12:32:57 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_data_setup(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		kill_program(game, e_mlx_init);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (game->win_ptr == NULL)
		kill_program(game, e_window_init);
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (game->img.mlx_img == NULL)
		kill_program(game, e_image_init);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
		&game->img.line_len, &game->img.endian);
}

int	main(void)
{
	t_game	game;

	printf("Hello!\n");
	printf("Libft test: %s", ft_strchr("Testing\n", 'T'));
	initialize_game_data(&game);
	game_data_setup(&game);
	mlx_loop_hook(game.mlx_ptr, &render, &game);
	mlx_hook(game.win_ptr, on_destroy, mask_no_event, &close_window, &game);
	mlx_hook(game.win_ptr, on_keydown, mask_key_press, &handle_keypress, &game);
	//mlx_hook(game.win_ptr, on_keydown, mask_no_event, &process_keypress, &game);
	//mlx_loop_hook(game.mlx_ptr, &process_keypress, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
	// gcc ./sources/main.c -lft -lmlx -lXext -lX11 -o test -I includes -I ./libs/minilibx -L ./libs -L ./libs/minilibx
	// gcc ./sources/*.c -lft -lmlx -lXext -lX11 -o test -fsanitize=leak -g -I includes -I ./libs/minilibx -L ./libs -L ./libs/minilibx && ./test
}
