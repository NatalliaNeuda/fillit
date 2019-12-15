/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:05:04 by nneuda            #+#    #+#             */
/*   Updated: 2019/12/11 23:20:25 by hyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*get_cell(char *s_input)
{
	char	*cell;
	int		i;
	char	*tmp;

	i = 0;
	cell = NULL;
	tmp = s_input;
	if (s_input[i])
		cell = ft_strsub(tmp, i, CELL);
	return (cell);
}

static char	*get_str(int fd)
{
	char	*line;
	char	*s;
	char	*tmp;

	s = ft_strnew(0);
	while (get_next_line(fd, &line) == 1)
	{
		if (line)
		{
			tmp = line;
			line = ft_strjoin(line, "\n");
			free(tmp);
			tmp = ft_strjoin(s, line);
			free(s);
			s = tmp;
			free(line);
		}
	}
	return (s);
}

static char	*fd_open(int argc, char *argv)
{
	int		fd;
	char	*s;

	if (argc == 1)
		fd = 0;
	if (argc == 2)
		fd = open(argv, O_RDONLY);
	else
	{
		ft_putstr("usage: ./fillit sample.txt\n");
		exit(1);
	}
	s = get_str(fd);
	close(fd);
	return (s);
}

static void	operate_str(int n_fig, t_fig *rec, char *s)
{
	int		name;
	char	*ptr;

	name = 0;
	while (name < n_fig && s != NULL)
	{
		ptr = get_cell(s);
		find_hash_coord(ptr, rec, name);
		free(ptr);
		shift_figure(&rec[name]);
		name++;
		s += CELL;
	}
}

int			main(int argc, char **argv)
{
	char	*s[2];
	int		n;
	int		n_fig;
	t_fig	rec[26];
	t_def	f_def[19];

	ft_bzero(&rec, sizeof(rec));
	s[0] = fd_open(argc, argv[1]);
	s[1] = s[0];
	if (s[0] != NULL)
		n_fig = ft_cells_count(s[0]);
	if (s[0] != NULL && check_input(s[0], n_fig))
	{
		n = map_size(n_fig);
		create_def_figs(f_def);
		operate_str(n_fig, rec, s[0]);
		if (cmp_fig(rec, f_def, n_fig))
			increase_map(n, rec);
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("error\n");
	ft_strdel(&s[1]);
	return (0);
}
