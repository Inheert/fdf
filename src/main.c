/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:39:04 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/27 05:26:17 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/fdf.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*
*	Define ft_error for when something wrong happen
*	Argc == 2 only
*	Check if fd is valid
*	Check if map is valid:
*	- Same number of column for each row
*	- All column are valid (integer value)
*	- No unknow characters (number and one sep char only)
*/

static void ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	display_map(int **map, int line_len)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < line_len)
		{
			ft_printf("%d ", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		**map;
	char	*path;
	int		line_len;

	if (argc != 2)
		ft_error();
	line_len = 0;
	map = NULL;
	path = ft_strjoin("src/maps/", argv[1]);
	if (!path || !get_map(path, &map, &line_len))
		return (free_ptrptr((void ***)&map), 0);
	display_map(map, line_len);
	free_ptrptr((void ***)&map);
	free(path);
	return (0);
}
