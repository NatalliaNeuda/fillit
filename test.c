/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:05:04 by nneuda            #+#    #+#             */
/*   Updated: 2019/11/16 23:16:47 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "fillit.h"

static int ft_cells_count(char *s_input)
{
    int hash;
    int n_fig;

    n_fig = 0;
    hash = 0;
    while (*s_input)
    {
        if (*s_input == '#')
            hash++;
        s_input++;
    }
    n_fig = hash/LEN;
        return (n_fig);
}

static int check_input(char *s_input)
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
            if (s_input[i] == '#')
                q_hashs++;
            if (s_input[i] == '\n')
                q_newlines++;
            i++;    
    }
        q_newlines++;
        if (q_dots % 12 != 0 || q_hashs % 4 != 0 || q_newlines % 5 != 0)
            return (0);              
    return(1);
}


static char *get_cell(char *s_input)
{
    char *cell;
    int i;
    char *tmp;
    
    i = 0;
    tmp = s_input; 
    if (s_input[i])
        cell = ft_strsub(tmp, i, CELL);
    return (cell);
}


static int min_cord(int *cord)
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

static void find_hash_coord(char *cell, t_fig *rec, int nn)
{
    int i;
    int j;
    int x[4];
    int y[4];

    i = 0;
    j = 0;
    while (cell[i] && j < 4)
    {
            if (cell[i] == '#')
            {
                x[j] = i % 5;
                y[j] = i / 5;  
                j++;
        }
        i++;
    }
    i = 0;
    int min_x = min_cord(x);
    int min_y = min_cord(y);
    while (i < 4)
    {
        rec[nn].x[i] = x[i] - min_x;
        rec[nn].y[i] = y[i] - min_y;
        i++;   
    }
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

static int cmp_fig(t_fig *f, t_def *f_def, int n_fig)
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


int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
    char    *s;
	int 	i;
	int 	j;
    int n;
    int nn;
    t_fig rec[26];
    t_def f_def[19];
        
	i = 0;
	j = 0;
    nn = 0;
	if (argc == 1)
		fd = 0;  
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
        if (s == NULL)
			s = ft_strnew(1);
		if (line)
		{
			line = ft_strjoin(line, "\n");
			char *tmp = ft_strjoin(s, line);
			free(s);
			s = tmp;
		}
	} 
	if (argc == 2)
		close(fd);
    int n_fig = ft_cells_count(s); 
	n = map_size(n_fig);
    char map[n][n];
    create_map(n, map);
    create_def_figs(f_def);
    if (check_input(s))
    {
        while (nn < n_fig && s != NULL)
        {
            find_hash_coord(get_cell(s), rec, nn);
            nn++;
            s += CELL;
        } 
        if (cmp_fig(rec, f_def, n_fig))
            printf("1");
        else
            printf("0");
    }
    return(0);
}

