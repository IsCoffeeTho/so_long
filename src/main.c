/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:43:27 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/12 00:54:29 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

/*
	This graphics implementation is made to be able to run on the CPU.
	if you are concerned of running this on your machine, DONT RUN IT.
*/

void	safe_free(t_game *ins)
{
	if (ins->win)
		mlx_destroy_window(ins->mlx, ins->win);
	free(ins->mlx);
}

int	good_exit(t_game *instance)
{
	safe_free(instance);
	exit(0);
}

int	bad_exit(t_game *instance)
{
	safe_free(instance);
	exit(1);
}

int	main(int c, char **v)
{
	t_game	instance;

	if (c != 2)
		return (0);
	ft_memset(&instance, 0, sizeof(t_game));
	load_map(&instance, v);
	check_for_errors(&instance);
	instance.mlx = mlx_init();
	instance.win = mlx_new_window(instance.mlx, (instance.map->width * 40),
			(instance.map->height * 40), "so_long");
	init_sprites(&instance);
	render_frame(&instance);
	mlx_key_hook(instance.win, control_scheme, &instance);
	mlx_hook(instance.win, 17, 0, (void *)exit, 0);
	mlx_loop(instance.mlx);
}
