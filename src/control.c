/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:43:27 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/12 14:05:44 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	up(t_game *game)
{
	if (game->map->map_rows[game->player->y - 1][game->player->x] == '1')
		return (0);
	game->player->y--;
	game->player->entity->y--;
	game->score++;
	return (1);
}

int	down(t_game *game)
{
	if (game->map->map_rows[game->player->y + 1][game->player->x] == '1')
		return (0);
	game->player->y++;
	game->player->entity->y++;
	game->score++;
	return (1);
}

int	left(t_game *game)
{
	if (game->map->map_rows[game->player->y][game->player->x - 1] == '1')
		return (0);
	game->player->x--;
	game->player->entity->x--;
	game->score++;
	return (1);
}

int	right(t_game *game)
{
	if (game->map->map_rows[game->player->y][game->player->x + 1] == '1')
		return (0);
	game->player->x++;
	game->player->entity->x++;
	game->score++;
	return (1);
}

int	control_scheme(int keycode, t_game *game)
{
	int	rint;

	rint = 0;
	if (keycode == 53 || keycode == 65307)
		good_exit(game);
	else if (keycode == 13 || keycode == 119)
		rint = up(game);
	else if (keycode == 1 || keycode == 115)
		rint = down(game);
	else if (keycode == 0 || keycode == 97)
		rint = left(game);
	else if (keycode == 2 || keycode == 100)
		rint = right(game);
	if (rint)
	{
		ft_printf("move: %d\n", game->score);
		render_frame(game);
	}
	return (1);
}
