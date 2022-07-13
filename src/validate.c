/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:31:47 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/13 12:26:01 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	validate_size(t_game *game)
{
	int	row_len;
	int	row_i;

	row_i = 0;
	while (row_i < game->map->height)
	{
		row_len = ft_strlen(game->map->map_rows[row_i]);
		if (game->map->map_rows[row_i][row_len - 1] == '\n')
			row_len--;
		if (row_len != game->map->width)
		{
			ft_printf("\e[91m\e[1mError\e[39m Line %d, Col %d\e[0m: %s\n",
				row_i + 1, row_len, "Map must be a rectangle or square.");
			return (1);
		}
		row_i++;
	}
	return (0);
}

int	validate_entities(t_game *game)
{
	if (game->exitable && game->playable && (game->win_threshold != 0))
		return (0);
	ft_printf("\e[91m\e[1mError\e[0m %s\n",
		"Map has missing details.");
	return (1);
}

static	int	validate_line(char *line, int lat, int size)
{
	int	i;

	i = 0;
	if (lat)
	{
		while (i < size)
		{
			if (line[i++] != '1')
			{
				ft_printf("\e[91m\e[1mError\e[0m %s\n",
					"Map border is incomplete.");
				return (1);
			}
		}
	}
	else
	{
		if (line[0] != '1')
			return (1);
		if (line[size - 1] != '1')
			return (1);
	}
	return (0);
}

int	validate_wall(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		if (validate_line(game->map->map_rows[y],
				(y == 0) || (y == game->map->height - 1),
				game->map->width))
			return (1);
		y++;
	}
	return (0);
}

int	validate_entries(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			tile = game->map->map_rows[y][x];
			if (tile != '0' && tile != '1'
				&& tile != 'C' && tile != 'E'
				&& tile != 'P')
			{
				ft_printf("\e[91m\e[1mError\e[39m Line %d, Col %d\e[0m: %s\n",
					y+1, x+1, "Map has invalid tile.");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
