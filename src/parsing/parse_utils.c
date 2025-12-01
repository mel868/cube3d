/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:00:05 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 15:00:06 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_spaces(char *str)
{
	if (!str)
		return (NULL);
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

int	is_empty_line(char *line)
{
	if (!line)
		return (1);
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	parse_texture_path(char *line, char **path)
{
	char	*start;
	char	*end;
	int		len;

	line = skip_spaces(line);
	start = line;
	while (*line && *line != ' ' && *line != '\t' && *line != '\n')
		line++;
	end = line;
	len = end - start;
	if (len == 0)
		return (-1);
	*path = malloc(sizeof(char) * (len + 1));
	if (!*path)
		return (-1);
	len = 0;
	while (start < end)
		(*path)[len++] = *start++;
	(*path)[len] = '\0';
	return (0);
}
