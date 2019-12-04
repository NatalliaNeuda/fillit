/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:05:04 by nneuda            #+#    #+#             */
/*   Updated: 2019/12/03 16:13:23 by nneuda           ###   ########.fr       */
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

void find_hash_coord(char *cell, t_fig *rec, int nn)
{
    int i;
    int j;

    i = 0;
    j = 0;
    rec[nn].NAME = nn + 'A';
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

static char *get_cell(char *s_input)
{
    char *cell;
    int i;
    char *tmp;
    
    i = 0;
    cell = NULL;
    tmp = s_input; 
    if (s_input[i])
        cell = ft_strsub(tmp, i, CELL);
    return (cell);
}
/*
static void ft_read(int ac)
{
    int fd;
    
    fd = 0;
    if (ac == 1)
	 	fd = 0;  
	if (ac == 2)
		fd = open(argv[1], O_RDONLY);
	else
		ft_putstr("usage: ./a.out sample.txt");
    get_str(fd);
   
}*/

static char *get_str(int argc, char *argv)
{
    char *line;
    char *s;
    char *tmp; 
    int fd = 0;

   	if (argc == 1)
	 	fd = 0;  
	if (argc == 2)
		fd = open(argv, O_RDONLY);
	else
		ft_putstr("usage: ./a.out sample.txt");
	while (get_next_line(fd, &line) == 1)
	{
        if (s == NULL)
			s = ft_strnew(1);
		if (line)
		{
			line = ft_strjoin(line, "\n");
			tmp = ft_strjoin(s, line);
			free(s);
			s = tmp;
		}
	}
    close(fd);
    return (s);
}


int		main(int argc, char **argv)
{
    char    *s;
	int 	i;
	int 	j;
    int     n;
    int     nn;
    int n_fig;
    t_fig rec[26];
    t_def f_def[19];

	i = 0;
	j = 0;
    nn = 0;
    n_fig = 0;
    s = get_str(argc, argv[1]);

    if (check_input(s))
    {
        n_fig = ft_cells_count(s); 
	    n = map_size(n_fig);
        char map[n][n];
        create_map(n, map);
        create_def_figs(f_def);
        while (nn < n_fig && s != NULL)
        {
            find_hash_coord(get_cell(s), rec, nn);
            shift_figure2(rec, nn);
            nn++;
            s += CELL;
        }
        if (cmp_fig(rec, f_def, n_fig))
            increase_map(n, rec, nn - 1);
        else 
            ft_putstr("error\n");
    }
    else
        ft_putstr("error\n");
        
    return(0);
}
