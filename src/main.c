/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:43:27 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/12 14:04:26 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	safe_free(t_game *g)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	free(g->mlx);
	free_map(g);
	free(g->player);
	free_entities(g);
}

int	good_exit(t_game *g)
{
	safe_free(g);
	exit(0);
}

int	bad_exit(t_game *g)
{
	safe_free(g);
	exit(1);
}

int	main(int c, char **v)
{
	t_game	instance;

	if (c != 2)
		return (0);
	ft_memset(&instance, 0, sizeof(t_game));
	load_map(&instance, v);
	if (check_for_errors(&instance))
		bad_exit(&instance);
	instance.mlx = mlx_init();
	instance.win = mlx_new_window(instance.mlx, (instance.map->width * 40),
			(instance.map->height * 40), "so_long");
	init_sprites(&instance);
	init_entities(&instance);
	establish_player(&instance);
	render_frame(&instance);
	mlx_key_hook(instance.win, &control_scheme, &instance);
	mlx_hook(instance.win, 17, 0, (void *)exit, 0);
	mlx_loop(instance.mlx);
}
