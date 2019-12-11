/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:27:14 by nneuda            #+#    #+#             */
/*   Updated: 2019/12/11 15:17:16 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "fillit.h"

static int	replace(int n, char **map, t_fig *rec, t_step d)
{
	int		i;

	i = -1;
	while (++i < LEN)
	{
		if (((*rec).x[i] + d.x > n - 1) || ((*rec).y[i] + d.y > n - 1) ||
				(map[(*rec).y[i] + d.y][(*rec).x[i] + d.x] != '.'))
			return (0);
	}
	i = 0;
	while (i < LEN)
	{
		(*rec).x[i] += d.x;
		(*rec).y[i] += d.y;
		i++;
	}
	return (1);
}

static void	write_to_map(char **map, t_fig *rec)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		map[(*rec).y[i]][(*rec).x[i]] = (*rec).name;
	}
}

static void	delete_from_map(char **map, t_fig *rec)
{
	int		i;

	i = 0;
	while (i < LEN)
	{
		map[(*rec).y[i]][(*rec).x[i]] = '.';
		i++;
	}
}

static int	backtrack(int n, t_fig *rec, char **map)
{
	t_step	dot;

	dot.y = -1;
	while (++(dot.y) < n)
	{
		dot.x = -1;
		while (++(dot.x) < n)
		{
			if (replace(n, map, rec, (t_step) {dot.x, dot.y}))
			{
				write_to_map(map, rec);
				if (!corr_name(rec[1].name) || (backtrack(n, rec + 1, map)))
					return (1);
				delete_from_map(map, rec);
				shift_figure(rec);
			}
		}
	}
	return (0);
}

void free_map(int n, char **map)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_strdel(&map[i]);
		i++;
	}
	ft_strdel(map);
}

void		increase_map(int n, t_fig *rec)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = malloc(sizeof(char*) * n + 1);
	while (++i < n)
	{
		map[i] = malloc(n + 1);
		map[i][n] = '\0';
	}
	map[n] = NULL;
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			map[i][j] = '.';
	}
	if (!backtrack(n, rec, map))
	{
		free_map(n, map);
		increase_map(n + 1, rec);
	}
	else
		print(n, map);
	free_map(n, map);
}
