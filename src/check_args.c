/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:37:57 by tclaereb          #+#    #+#             */
/*   Updated: 2024/03/27 05:09:48 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_ptrptr(void ***map)
{
	int	i;

	if (!map || !*map)
		return ;
	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

int	*convert_char_to_int(char **ptr, int *line_len)
{
	int	*new_ptr;
	int	len;
	int	i;

	if (!ptr || !line_len)
		return (NULL);
	len = 0;
	while (ptr[len])
		len++;
	if (*line_len == 0)
		*line_len = len - 1;
	else if (*line_len != len - 1)
		return (NULL);
	new_ptr = malloc(len * sizeof(int));
	if (!new_ptr)
		return (free_ptrptr((void ***)&ptr), NULL);
	i = 0;
	while (ptr[i] && i < len - 1)
	{
		new_ptr[i] = ft_atoi(ptr[i]);
		i++;
	}
	return (free_ptrptr((void ***)&ptr), new_ptr);
}

int	**get_map(char *filename, int ***map, int *line_len)
{
	char		*line;
	int			i;
	int			fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	i = 0;
	*map = malloc(500 * sizeof(char *));
	if (!*map)
		return (NULL);
	while (line)
	{
		(*map)[i] = convert_char_to_int(ft_split(line, ' '), line_len);
		if (!(*map)[i])
			return (NULL);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	(*map)[i] = NULL;
	return (*map);
}
