/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:05:04 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/27 00:04:16 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"

int        ft_hash_dot_count(char **tile)
{
    int     x;
    int     y;
    int     dot;
    int     hash;
//i = 0;
    x = 0;
    y = 0;
    dot = 0;
    hash = 0;
    while (y < 4)
    {
        x = 0;
        while (x < 4)
        {
            if (tile[y][x] == '.')
                dot++;
            else if (tile[y][x] == '#')
                hash++;
            ft_putchar(tile[y][x]);
            x++;
        }
        y++;
    }
    if (dot == 16 || hash == 4)
        return (1);
    else
        return (0);
}

int        **ft_get_coordinate(char **tile)
{
    int        **coord;
    int        i;
    int        j;
    int        x;
    int        y;
    i = 0;
    coord = (int**)malloc(4 * sizeof(int*));
    while (i < 4)
    {
        coord[i] = (int*)malloc(2 * sizeof(int));
        i++;
    }
    i = 0;
    j = 0;
    x = 0;
    y = 0;
    while (y < 4)
    {
        //ft_putchar('a');
        x = 0;
        while (x < 4)
        {
            //ft_putchar('b');
            if (tile[y][x] == '#' && i < 4)
            {
                //ft_putchar('c');
                coord[i][0] = x;
                //ft_putnbr(x);
                coord[i][1] = y;
                //ft_putnbr(coord[i][1]);
                //coord[i][2] = '\0';
                i++;
            }
           x++;
        }
        y++;
    }
    x = 0;
    y = 0;
    while (    y < 3)
    {
        x = 0;
        while (x < 2)
        {
            ft_putnbr(coord[y][x]);
            x++;
        }
        y++;
    }
    
    /*while (tile[y][x] != '#' && tile[y][x])
        x++;
    
    if    (tile[y][x] == '#')
    {
        coord[i][0] = x;
        ft_putnbr(coord[i][0]);
        //j++;
        coord[i][1] = y;
        ft_putnbr(coord[i][1]);
        i++;
    }
    if (x < 4)
    {
        while (tile[y][x] != '#' && tile[y][x])
            x++;
    }
    y++;*/
    
    //ft_putchar(tile[y][x]);
    return (coord);
}