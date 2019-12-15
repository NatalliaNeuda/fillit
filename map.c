/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 00:21:17 by nneuda            #+#    #+#             */
/*   Updated: 2019/12/11 23:04:43 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		map_size(int n_fig)
{
	int	n;

	n = 2;
	while ((n_fig * LEN) > (n * n))
		n++;
	return (n);
}

void	create_map(int n, char ***map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			(*map)[i][j] = '.';
	}
}

void	print(int n, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			ft_putchar(map[i][j]);
		ft_putendl("");
	}
}

int		corr_name(char c)
{
	if (c >= 'A' && c <= 'X')
		return (1);
	return (0);
}

void	free_map(int n, char **map)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}
