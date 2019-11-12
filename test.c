/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:05:04 by nneuda            #+#    #+#             */
/*   Updated: 2019/11/04 14:41:23 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "fillit.h"

int        ft_cells_count(char **tile)
{
    int     hash;
	int     i;
	int     j;
    int     n_fig;
        
	i = 0;
	hash = 0;
    while (tile[i])
    {
		j = 0;
        while (tile[i][j])  
        {
            if (tile[i][j] == '#')
                hash++;
            j++;
        }
        i++;
    }
	n_fig = hash/LEN;
        return (n_fig);
}

int map_size(int n_fig)
{
    int n;

    n = 2;
    while (n_fig * LEN > n * n)
        n++;
    ft_putnbr(n);
    write(1, "\n", 1);
    return (n);
}

static void create_map(int n, char map[n][n])
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

/*
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
    while (y < 3)
    {
        x = 0;
        while (x < 2)
        {
            ft_putnbr(coord[y][x]);
            x++;
        }
        y++;
    }
    
    while (tile[y][x] != '#' && tile[y][x])
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
    y++;
    
    ft_putchar(tile[y][x]);
    return (coord);
}*/



int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
    char   **s;
	int 	i;
	int 	j;
    int n;
    int x;
    int y; 
        
    x = 0;
	i = 0;
	j = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	s = (char **)(malloc(20 * sizeof(char*)));
	while (get_next_line(fd, &line) == 1)
	{
		s[i] = ft_strdup(line);
		i++;
	}
	i = 0;
	while (s[i])
	{
		ft_putendl(s[i]);
		i++;
	}
	if (argc == 2)
		close(fd);
	n = map_size(ft_cells_count(s));
    char map[n][n];
    create_map(n, map);
    x = -1;
    while (++x < n)
    {
        y = -1;
        while (++y < n)
            printf("%c", map[x][y]);
        printf("\n");
    }
    return(0);



//	while (i >= 0)
//		i-- = ft_hash_dot_count(s);
	//printf("\n i = %d\n", i);
}

