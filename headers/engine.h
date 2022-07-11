/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:09:34 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/11 23:53:49 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_entity
{
	int	type;
	int	x;
	int	y;
}	t_entity;

typedef struct s_sprite
{
	int		ltype;
	void	*image;
	int		height;
	int		width;
}	t_sprite;

typedef struct s_map
{
	int		fd;
	int		height;
	int		width;
	char	**map_rows;
}	t_map;

typedef struct s_plyr
{
	int	x;
	int	y;
	int	facing;
	int	(*up)();
	int	(*down)();
	int	(*left)();
	int	(*right)();
}	t_plyr;

typedef struct s_instance
{
	t_map		*map;
	t_plyr		*player;
	t_entity	**entities;
	t_sprite	**sprites;
	int			entity_count;
	int			win_threshold;
	void		*mlx;
	void		*win;
}	t_game;

int		good_exit(t_game *instance);
int		load_map(t_game *game, char **argv);
int		control_scheme(int keycode, t_game *game);
int		isentity(char t);
void	init_sprites(t_game *game);
void	init_entities(t_game *game);
void	render_backgorund(t_game *game);
void	render_entity(t_entity *entity);
void	render_frame(t_game *game);
int		check_for_errors(t_game *game);

#endif