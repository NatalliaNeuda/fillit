/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:27:14 by nneuda            #+#    #+#             */
/*   Updated: 2019/11/30 23:15:52 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "fillit.h"

int map_size(int n_fig)
{
    int n;

    n = 2;
    while (n_fig * LEN > n * n)
        n++;
    return (n);
}

void create_map(int n, char map[n][n])
{
    int i;
    int j;
    
    i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			map[i][j] = '.';
	}
}
// function  replace move figures if it's posible and reset cordinates if yes
static int replace(int n, char map[n][n], t_fig *rec, int x, int y)
{
    int i;
    
    i = -1;
    while (++i < LEN)
    {
        if (((*rec).x[i] + x > n - 1) || ((*rec).y[i] + y > n - 1) || map[(*rec).y[i] + y][(*rec).x[i] + x] != '.')
            return (0);
    }
    i = 0;
    while (i < LEN)
    {
        (*rec).x[i] += x;
        (*rec).y[i] += y;
        i++;
    }

    return (1); 
}

// function write_to_map write letters on the map
static void write_to_map(int n, char map[n][n], t_fig *rec)
{
    int i;

    i = -1;
	while (++i < 4)
    {
        map[(*rec).y[i]][(*rec).x[i]] = (*rec).NAME;
    }
		
}

// function delete_from_map delete from map
static void delete_from_map(int n, char map[n][n], t_fig *rec)
{
    int i;

    i = 0;
    while (i < n)
    {
        map[(*rec).y[i]][(*rec).x[i]] = '.';
        i++;
    }
}

static int	backtrack(int n, t_fig *rec, char map[n][n], int nn)
{
	int x;
	int y;

    y = -1;
	while (++y < n)
	{
        x = -1;
		while (++x < n)
		{
			if (replace(n, map, rec, x, y))
			{
				write_to_map(n, map, rec);
				if (!IS_FIG(rec[1].NAME) || backtrack(n, rec + 1, map, nn))
					return (1);
				delete_from_map(n, map, rec);
				shift_figure(rec);
			}
		}
	}

	return (0);
}

void increase_map(int n, t_fig *rec, int nn)
{
    char map[n][n];

    create_map(n, map);
	if (!backtrack(n, rec, map, nn))
	{
		increase_map(n + 1, rec, nn);
	}
	else
		print(n, map);
    
}

