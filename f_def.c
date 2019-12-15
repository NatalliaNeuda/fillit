/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_def.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:22:06 by nneuda            #+#    #+#             */
/*   Updated: 2019/12/11 18:30:46 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	f_def_record(t_def *rec, int *x, int *y, int q)
{
	int		i;

	i = 0;
	while (i < LEN)
	{
		rec[q].x[i] = x[i];
		rec[q].y[i] = y[i];
		i++;
	}
}

void		create_def_figs(t_def *rec)
{
	f_def_record(rec, (int[LEN]){0, 0, 1, 0}, (int[LEN]){0, 1, 1, 2}, 0);
	f_def_record(rec, (int[LEN]){1, 0, 1, 1}, (int[LEN]){0, 1, 1, 2}, 1);
	f_def_record(rec, (int[LEN]){0, 1, 2, 1}, (int[LEN]){0, 0, 0, 1}, 2);
	f_def_record(rec, (int[LEN]){1, 0, 1, 2}, (int[LEN]){0, 1, 1, 1}, 3);
	f_def_record(rec, (int[LEN]){0, 0, 1, 2}, (int[LEN]){0, 1, 1, 1}, 4);
	f_def_record(rec, (int[LEN]){0, 1, 1, 2}, (int[LEN]){0, 0, 1, 1}, 5);
	f_def_record(rec, (int[LEN]){1, 0, 1, 0}, (int[LEN]){0, 1, 1, 2}, 6);
	f_def_record(rec, (int[LEN]){1, 1, 0, 1}, (int[LEN]){0, 1, 2, 2}, 7);
	f_def_record(rec, (int[LEN]){0, 1, 2, 2}, (int[LEN]){0, 0, 0, 1}, 8);
	f_def_record(rec, (int[LEN]){0, 1, 0, 0}, (int[LEN]){0, 0, 1, 2}, 9);
	f_def_record(rec, (int[LEN]){2, 0, 1, 2}, (int[LEN]){0, 1, 1, 1}, 10);
	f_def_record(rec, (int[LEN]){0, 1, 2, 0}, (int[LEN]){0, 0, 0, 1}, 11);
	f_def_record(rec, (int[LEN]){0, 0, 1, 1}, (int[LEN]){0, 1, 1, 2}, 12);
	f_def_record(rec, (int[LEN]){1, 2, 0, 1}, (int[LEN]){0, 0, 1, 1}, 13);
	f_def_record(rec, (int[LEN]){0, 1, 1, 1}, (int[LEN]){0, 0, 1, 2}, 14);
	f_def_record(rec, (int[LEN]){0, 0, 0, 1}, (int[LEN]){0, 1, 2, 2}, 15);
	f_def_record(rec, (int[LEN]){0, 1, 0, 1}, (int[LEN]){0, 0, 1, 1}, 16);
	f_def_record(rec, (int[LEN]){0, 1, 2, 3}, (int[LEN]){0, 0, 0, 0}, 17);
	f_def_record(rec, (int[LEN]){0, 0, 0, 0}, (int[LEN]){0, 1, 2, 3}, 18);
}

void		find_hash_coord(char *cell, t_fig *rec, int nn)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	rec[nn].name = nn + 'A';
	while (cell[i] && j < 4)
	{
		if (cell[i] == '#')
		{
			rec[nn].x[j] = i % 5;
			rec[nn].y[j] = i / 5;
			j++;
		}
		i++;
	}
}

int			ft_cells_count(char *s_input)
{
	int		i;

	i = (ft_strlen(s_input) + 1) / 21;
	return (i);
}
