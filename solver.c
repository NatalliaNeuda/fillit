/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:27:14 by nneuda            #+#    #+#             */
/*   Updated: 2019/11/15 14:53:46 by nneuda           ###   ########.fr       */
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
   //for checking map size

    /*while (++x < n)
    {
        y = -1;
        while (++y < n)
            printf("%c", map[x][y]);
        printf("\n");
    }*/