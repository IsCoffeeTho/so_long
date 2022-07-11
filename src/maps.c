/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:43:27 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/11 18:10:31 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void	count_types(t_game *game)
{
	int	x;
	int	y;

	while (y < game->map->height)
	{
		while (x < game->map->width)
		{
			if (isentity(game->map->map_rows[y][x]))
				game->entity_count++;
			if (game->map->map_rows[y][x] == 'C')
				game->win_threshold++;
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

int	load_map(t_game *game, char **argv)
{
	char	*rowstr;

	game->map->fd = open(argv[1], 0);
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
