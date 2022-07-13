/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:31:47 by amenadue          #+#    #+#             */
/*   Updated: 2022/07/13 12:27:50 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	check_for_errors(t_game *game)
{
	return (validate_size(game)
		|| validate_wall(game)
		|| validate_entities(game)
		|| validate_entries(game));
}
