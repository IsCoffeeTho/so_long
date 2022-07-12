/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:43:27 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/12 04:47:29 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	isentity(char t)
{
	if (t == 'P'
		|| t == 'C'
		|| t == 'E')
		return (1);
	return (0);
}

int	char_to_ent_type(char c)
{
	if (c == 'P')
		return (1);
	else if (c == 'C')
		return (2);
	else if (c == 'E')
		return (3);
	else
		return (0);
}

void	new_entity(t_game *game, int type, int x, int y)
{
	t_entity	*entity;
	int			i;

	entity = (t_entity *) malloc(sizeof(t_entity));
	entity->x = x;
	entity->y = y;
	entity->type = type;
	i = 0;
	while (game->entities[i])
		i++;
	game->entities[i] = entity;
}

void	init_entities(t_game *game)
{
	int	x;
	int	y;

	game->entities = (t_entity **) ft_calloc((game->entity_count + 1),
			sizeof(t_entity *));
	game->entities[game->entity_count] = NULL;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (isentity(game->map->map_rows[y][x]))
			{
				new_entity(game, char_to_ent_type(game->map->map_rows[y][x]),
					x, y);
			}
			x++;
		}
		y++;
	}
}
