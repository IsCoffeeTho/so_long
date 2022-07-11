/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:20:00 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/11 18:19:03 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	draw_tile(t_game *game, int x, int y)
{
	if (game->map->map_rows[y][x] == '1')
		return ;
	else
		return ;
}

void	render_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_entity(t_entity *entity)
{
	ft_printf("Entity <%p> was rendered\n", entity);
	return ;
}

void	render_frame(t_game *game)
{
	int	i;

	render_background(game);
	i = 0;
	while (game->entities[i])
	{
		render_entity(game->entities[i]);
		i++;
	}
}
