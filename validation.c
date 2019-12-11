/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:04:59 by nneuda            #+#    #+#             */
/*   Updated: 2019/12/10 17:58:47 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int			check_input(char *s_input, int n_fig)
{
	int		i;
	int		q_hashs;
	int		q_dots;
	int		q_newlines;

	q_hashs = 0;
	q_dots = 0;
	q_newlines = 0;
	i = -1;
	while (s_input[++i])
	{
		if (s_input[i] == '.')
			q_dots++;
		else if (s_input[i] == '#')
			q_hashs++;
		else if (s_input[i] == '\n')
			q_newlines++;
		if ((s_input[i + 1]) && (i + 1) % 21 == 0 && s_input[i] != '\n')
			return (0);
	}
	q_newlines++;
	if (q_dots % 12 != 0 || (q_hashs / 4) != n_fig || (q_newlines % 5 != 0))
		return (0);
	return (1);
}

int			min_cord(int *cord)
{
	int		min;
	int		i;

	min = cord[0];
	i = 0;
	while (i < 4)
	{
		if (min > cord[i])
			min = cord[i];
		i++;
	}
	return (min);
}

static int	cmp_arrays(int *a, int *b)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (a[i] == b[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int			cmp_fig(t_fig *f, t_def *f_d, int n_fig)
{
	int		i;
	int		j;
	int		flag;

	j = 0;
	while (j < n_fig)
	{
		i = -1;
		while (++i < 19)
		{
			flag = 0;
			if (cmp_arrays(f[j].x, f_d[i].x) && cmp_arrays(f[j].y, f_d[i].y))
			{
				flag++;
				break ;
			}
		}
		if (flag)
			j++;
		else
			return (0);
	}
	return (1);
}

void		shift_figure(t_fig *rec)
{
	int		i;
	int		minx;
	int		miny;

	i = 0;
	minx = min_cord((*rec).x);
	miny = min_cord((*rec).y);
	while (i < 4)
	{
		(*rec).x[i] -= minx;
		(*rec).y[i] -= miny;
		i++;
	}
}
