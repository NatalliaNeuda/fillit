/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:47:46 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/27 09:56:25 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define LEN 4 
# define Q_POS 19

#include "LIBFT/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_point {
    int x[LEN];
    int y[LEN];
}       t_def;

#endif