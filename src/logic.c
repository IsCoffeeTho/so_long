/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:31:47 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/12 13:18:59 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void	eat(t_game *game, t_entity *ent)
{
	ent->type = 4;
	game->win_threshold--;
}

static void	win_game(t_game *game)
{
	ft_printf("You Win!\n");
	good_exit(game);
}

int	collision_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->entity_count)
	{
		if (game->entities[i] != game->player->entity)
		{
			if ((game->entities[i]->x == game->player->x)
				&& (game->entities[i]->y == game->player->y))
			{
				if (game->entities[i]->type == 2)
				{
					eat(game, game->entities[i]);
				}
				else if (game->entities[i]->type == 3)
				{
					if (game->win_threshold == 0)
						win_game(game);
				}
				return (0);
			}
		}
		i++;
	}
	return (0);
}
