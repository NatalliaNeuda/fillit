/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:47:46 by nneuda            #+#    #+#             */
/*   Updated: 2019/11/16 23:36:22 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define LEN 4 
# define Q_POS 19
# define CELL 21

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
void create_map(int n, char map[n][n]);
void create_def_figs(t_def *rec);

#endif