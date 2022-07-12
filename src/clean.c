/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:22:45 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/12 20:21:39 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	free_map(t_game *g)
{
	int	i;

	i = 0;
	if (g->map == NULL)
		return ;
	if (g->map->map_rows == NULL)
		return ;
	while (i < g->map->height)
	{
		if (g->map->map_rows[i] != NULL)
			free(g->map->map_rows[i]);
		i++;
	}
	free(g->map->map_rows);
	free(g->map);
}

void	free_entities(t_game *g)
{
	int	i;

	i = 0;
	if (g->entities == NULL)
		return ;
	while (i < g->entity_count)
	{
		if (g->entities[i] != NULL)
			free(g->entities[i]);
		i++;
	}
	free(g->entities);
}

void	free_sprites(t_game *g)
{
	free(g->sprite_sheet->background);
	free(g->sprite_sheet->foreground);
	free(g->sprite_sheet->player);
	free(g->sprite_sheet->collectable);
	free(g->sprite_sheet->exit);
	free(g->sprite_sheet->none);
	free(g->sprite_sheet);
}
