/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:47:46 by nneuda            #+#    #+#             */
/*   Updated: 2019/12/10 00:09:52 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define LEN 4 
# define Q_POS 19
# define CELL 21
# define IS_FIG(x) (x >= 'A' && x <= 'Z')

#include "LIBFT/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_point {
    int x[LEN];
    int y[LEN];
}       t_def;

typedef struct s_fpoint {
    char NAME;
    int x[LEN];
    int y[LEN];
}       t_fig;

int map_size(int n_fig);
void create_map(int n, char ***map);
void create_def_figs(t_def *rec);
void find_hash_coord(char *cell, t_fig *rec, int nn);
void shift_figure(t_fig *rec);
int min_cord(int *cord);
int check_input(char *s_input, int n_fig);
int cmp_fig(t_fig *f, t_def *f_def, int n_fig);
void shift_figure2(t_fig *rec, int mm);
void	print(int n, char **map);
void increase_map(int n, t_fig *rec);

#endif