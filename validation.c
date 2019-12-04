/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:04:59 by nneuda            #+#    #+#             */
/*   Updated: 2019/12/04 13:34:55 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int check_input(char *s_input)
{
    int i;
    int i_tmp;
    int q_hashs;
    int q_dots;
    int q_newlines;

    i = 0;
    i_tmp = i;
    while (s_input[i])
    {
        if (s_input[i] == '\n')
            return(0);
        q_hashs = 0;
        q_dots = 0;
        q_newlines = 0;
        while (i < i_tmp + CELL - 1)
        {
            if (s_input[i] == '.')
                q_dots++;
            else if (s_input[i] == '#')
                q_hashs++;
            else if (s_input[i] == '\n')
                q_newlines++;
            else
                return(0);
            i++;    
        }
        q_newlines++;
        if (!(q_dots == 12) || !(q_hashs == 4) || !(q_newlines == 5))
            return (0);  
        i_tmp += CELL; 
        i++;
    }            
    return(1);
}
/*
int check_input(char *s_input)
{
    int i;
    int i_tmp;
    int q_hashs = 0;
    int q_dots = 0;
    int q_newlines = 0;

    i = 0;
    i_tmp = 0;
    while (s_input[i])
    {
            if (s_input[i] == '.')
                q_dots++;
            else if (s_input[i] == '#')
                q_hashs++;
            else if (s_input[i] == '\n')
                q_newlines++;
            else 
                return(0);            
            i++;    
    }
        q_newlines++;
        if (q_dots % 12 != 0 || q_hashs % 4 != 0 || q_newlines % 5 != 0)
            return (0);              
    return(1);
}*/

int min_cord(int *cord)
{
    int min;
    int i;

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

static int cmp_arrays(int *a, int *b)
{
    int i;
    
    i = 0;
    while (i < 4)
    {
        if(a[i] == b[i])
            i++;
        else
            return (0);
    }
    return (1);
}

int cmp_fig(t_fig *f, t_def *f_def, int n_fig)
{
    int i;
    int j;
    int flag;

    i = 0;
    j = 0;    
    while (j < n_fig)
    {
        i = 0;
        while (i < 19)
        {
            flag = 0;  
            if ((cmp_arrays(f[j].x, f_def[i].x)) && (cmp_arrays(f[j].y, f_def[i].y)))
            {
                flag++;
                break;
            }
            i++;                            
        }
        if(flag)
            j++;
        else
            return(0);
    }
    return(1);
}

void shift_figure2(t_fig *rec, int mm)
{
    int i;

    i = 0;
    int min_x = min_cord(rec[mm].x);
    int min_y = min_cord(rec[mm].y);
    while (i < 4)
    {
        rec[mm].x[i] -= min_x;
        rec[mm].y[i] -= min_y;
        i++;   
    }
}
void shift_figure(t_fig *rec)
{
    int i;

    i = 0;
    int min_x = min_cord((*rec).x);
    int min_y = min_cord((*rec).y);
    while (i < 4)
    {
        (*rec).x[i] -= min_x;
        (*rec).y[i] -= min_y;
        i++;   
    }
}

void	print(int n, char map[n][n])
{
	int		i;
	int		j;

    i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			ft_putchar(map[i][j]);
		ft_putendl("");
	}
}