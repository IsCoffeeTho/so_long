/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:09:34 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/13 12:39:10 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

# define BG_SPRITE "sprites/bg.xpm"
# define FG_SPRITE "sprites/fg.xpm"
# define PLY_SPRITE "sprites/me.xpm"
# define CL_SPRITE "sprites/cl.xpm"
# define EX_SPRITE "sprites/ex.xpm"
# define NULL_SPRITE "sprites/null.xpm"

typedef struct s_sprites
{
	void	*background;
	void	*foreground;
	void	*player;
	void	*collectable;
	void	*exit;
	void	*none;
}	t_sprites;

typedef struct s_entity
{
	int	type;
	int	x;
	int	y;
}	t_entity;

typedef struct s_map
{
	int		fd;
	int		height;
	int		width;
	char	**map_rows;
}	t_map;

typedef struct s_plyr
{
	int			eid;
	t_entity	*entity;
	int			x;
	int			y;
}	t_plyr;

typedef struct s_instance
{
	t_map		*map;
	t_plyr		*player;
	t_entity	**entities;
	t_sprites	*sprite_sheet;
	int			entity_count;
	int			win_threshold;
	int			exitable;
	int			playable;
	int			score;
	void		*mlx;
	void		*win;
}	t_game;

int		good_exit(t_game *instance);
int		bad_exit(t_game *instance);
int		load_map(t_game *game, char **argv);
int		control_scheme(int keycode, t_game *game);
int		isentity(char t);
int		collision_check(t_game *game);
void	establish_player(t_game *game);
void	free_map(t_game *g);
void	free_entities(t_game *g);
void	init_sprites(t_game *game);
void	init_entities(t_game *game);
void	render_backgorund(t_game *game);
void	render_entity(t_game *game, t_entity *entity);
void	render_frame(t_game *game);
int		validate_size(t_game *game);
int		validate_entities(t_game *game);
int		validate_wall(t_game *game);
int		validate_entries(t_game *game);
int		check_for_errors(t_game *game);

#endif