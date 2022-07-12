/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:20:00 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/12 13:07:32 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	init_sprites(t_game *game)
{
	int	x;
	int	y;

	game->sprite_sheet = (t_sprites *) ft_calloc(1, sizeof(t_sprites));
	game->sprite_sheet->background = mlx_xpm_file_to_image(game->mlx,
			BG_SPRITE, &x, &y);
	game->sprite_sheet->foreground = mlx_xpm_file_to_image(game->mlx,
			FG_SPRITE, &x, &y);
	game->sprite_sheet->player = mlx_xpm_file_to_image(game->mlx,
			PLY_SPRITE, &x, &y);
	game->sprite_sheet->collectable = mlx_xpm_file_to_image(game->mlx,
			CL_SPRITE, &x, &y);
	game->sprite_sheet->exit = mlx_xpm_file_to_image(game->mlx,
			EX_SPRITE, &x, &y);
	game->sprite_sheet->none = mlx_xpm_file_to_image(game->mlx,
			NULL_SPRITE, &x, &y);
}

void	draw_tile(t_game *game, int x, int y)
{
	if (game->map->map_rows[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite_sheet->background, x * 40, y * 40);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite_sheet->foreground, x * 40, y * 40);
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

void	render_entity(t_game *game, t_entity *entity)
{
	if (entity->type == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite_sheet->player, entity->x * 40, entity->y * 40);
	else if (entity->type == 2)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite_sheet->collectable, entity->x * 40, entity->y * 40);
	else if (entity->type == 3)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite_sheet->exit, entity->x * 40, entity->y * 40);
	else if (entity->type != 4)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite_sheet->none, entity->x * 40, entity->y * 40);
}

void	render_frame(t_game *game)
{
	int	i;

	render_background(game);
	collision_check(game);
	i = 0;
	while (i < game->entity_count)
	{
		render_entity(game, game->entities[i]);
		i++;
	}
}
