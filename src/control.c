/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:43:27 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/11 15:03:39 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	control_scheme(int keycode, t_game *game)
{
	int	rint;

	if (keycode == 53)
		good_exit(game);
	if (keycode == 13)
		rint = game->player->up();
	if (keycode == 1)
		rint = game->player->down();
	if (keycode == 0)
		rint = game->player->left();
	if (keycode == 2)
		rint = game->player->right();
	if (rint)
		render_frame(game);
	return (1);
}
