/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:39:28 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/27 04:44:06 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_map_info
{
	int	row_len;
	int	col_len;
} t_map_info;

void	free_ptrptr(void ***map);
int		**get_map(char *filename, int ***map, int *line_len);

#endif
