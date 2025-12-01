/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferaoun <mferaoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:59:21 by mferaoun          #+#    #+#             */
/*   Updated: 2025/12/01 14:59:23 by mferaoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_rgb_value(char *str, int *value)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (i == 0 || i > 3 || num < 0 || num > 255)
		return (-1);
	*value = num;
	return (i);
}

static char	*parse_one_value(char *str, int *value)
{
	int	offset;

	str = skip_spaces(str);
	offset = parse_rgb_value(str, value);
	if (offset < 0)
		return (NULL);
	return (str + offset);
}

int	parse_color(char *str, t_color *color)
{
	str = parse_one_value(str, &color->r);
	if (!str || *skip_spaces(str) != ',')
		return (-1);
	str = skip_spaces(str) + 1;
	str = parse_one_value(str, &color->g);
	if (!str || *skip_spaces(str) != ',')
		return (-1);
	str = skip_spaces(str) + 1;
	str = parse_one_value(str, &color->b);
	if (!str)
		return (-1);
	str = skip_spaces(str);
	if (*str != '\0' && *str != '\n')
		return (-1);
	return (0);
}
