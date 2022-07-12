/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:43:27 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/12 04:50:52 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	establish_player(t_game *game)
{
	int	i;

	i = 0;
	game->score = 0;
	game->player = (t_plyr *) ft_calloc(1, sizeof(t_plyr));
	while (i < game->entity_count)
	{
		if (game->entities[i]->type == 1)
		{
			game->player->entity = game->entities[i];
			game->player->x = game->entities[i]->x;
			game->player->y = game->entities[i]->y;
			game->player->eid = i;
			return ;
		}
		i++;
	}
}

static void	count_types(t_game *game)
{
	int	x;
	int	y;

	game->entity_count = 0;
	game->win_threshold = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (isentity(game->map->map_rows[y][x]))
				game->entity_count++;
			if (game->map->map_rows[y][x] == 'C')
				game->win_threshold++;
			if (game->map->map_rows[y][x] == 'E')
				game->exitable = 1;
			if (game->map->map_rows[y][x] == 'P')
				game->playable = 1;
			x++;
		}
		y++;
	}
}

static int	append_map_row(t_game *game, char *row)
{
	char	**temporary;
	int		i;

	if (!row)
		return (0);
	i = 0;
	game->map->height++;
	temporary = (char **)malloc(sizeof(char *) * (game->map->height + 1));
	temporary[game->map->height] = NULL;
	while (i < game->map->height - 1)
	{
		temporary[i] = game->map->map_rows[i];
		i++;
	}
	temporary[i] = row;
	if (game->map->map_rows)
		free(game->map->map_rows);
	game->map->map_rows = temporary;
	return (1);
}

int	load_map(t_game *game, char **v)
{
	char	*rowstr;

	game->map = (t_map *) ft_calloc(1, sizeof(t_map));
	game->map->fd = open(v[1], 0);
	if (game->map->fd < 0)
		return (0);
	while (1)
	{
		rowstr = get_next_line(game->map->fd);
		if (!append_map_row(game, rowstr))
			break ;
	}
	close (game->map->fd);
	game->map->width = ft_strlen(game->map->map_rows[0]);
	if (game->map->map_rows[0][game->map->width - 1] == '\n')
		game->map->width--;
	count_types(game);
	return (1);
}
