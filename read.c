/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 22:47:42 by nneuda            #+#    #+#             */
/*   Updated: 2019/10/27 10:10:19 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
    char    *s; 


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
			line = ft_strjoin(line, "\n");
		char* tmp = ft_strjoin(s, line);
		free(s);
		s = tmp;
	}
	if (argc == 2)
		close(fd);
    printf("%s", s);
}