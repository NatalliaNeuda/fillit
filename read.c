/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:05:04 by nneuda            #+#    #+#             */
/*   Updated: 2019/12/11 15:19:34 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "fillit.h"

static int	ft_cells_count(char *s_input)
{
	int		i;

	i = (ft_strlen(s_input) + 1) / 21;
	return (i);
}

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

static char	*get_str(int argc, char *argv)
{
	char	*line;
	char	*s;
	char	*tmp;
	int		fd;

	if (argc == 1)
		fd = 0;
	if (argc == 2)
		fd = open(argv, O_RDONLY);
	else
		ft_putstr("usage: ./fillit sample.txt");
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
	close(fd);
	return (s);
}

static void	operate_str(int n_fig, t_fig *rec, char *s)
{
	int		name;

	name = 0;
	while (name < n_fig && s != NULL)
	{
		find_hash_coord(get_cell(s), rec, name);
		shift_figure(&rec[name]);
		name++;
		s += CELL;
	}
}

int			main(int argc, char **argv)
{
	char	*s;
	int		n;
	int		n_fig;
	t_fig	rec[26];
	t_def	f_def[19];

	ft_bzero(&rec, sizeof(rec));
	s = get_str(argc, argv[1]);
	if (s != NULL)
		n_fig = ft_cells_count(s);
	if (s != NULL && check_input(s, n_fig))
	{
		n = map_size(n_fig);
		create_def_figs(f_def);
		operate_str(n_fig, rec, s);
		if (cmp_fig(rec, f_def, n_fig))
			increase_map(n, rec);
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("error\n");
	// while(1)
	// ;
	return (0);
}
