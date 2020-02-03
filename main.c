/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <smoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:29:42 by smoreno-          #+#    #+#             */
/*   Updated: 2019/01/04 02:09:38 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	ft_maplen(t_lst_map *lst)
{
	size_t		i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

static char		**ft_firstalloc(int sqrt_size)
{
	char	**tab;
	int		i;
	int		j;

	i = -1;
	if (!(tab = (char **)malloc(sizeof(char *) * (sqrt_size + 1))))
		return (NULL);
	while (++i < sqrt_size)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * (sqrt_size + 1))))
		{
			j = 0;
			while (j < sqrt_size + 1)
			{
				free(tab[j]);
				j++;
			}
			free(tab);
			return (NULL);
		}
		ft_memset(tab[i], '.', sqrt_size);
		tab[i][sqrt_size] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}

static int		ft_checkargc(int argc)
{
	if (argc != 2)
	{
		write(1, "usage: fillit file ...\n ", 23);
		return (-1);
	}
	return (0);
}

int				ft_error(int fd, int sw)
{
	if (sw == 1)
		close(fd);
	ft_putendl("error");
	return (-1);
}

int				main(int argc, char **argv)
{
	char		**tab;
	int			sqrt_size;
	int			fd;
	t_lst_map	*ptr_map;
	t_lst_map	*par_lst;

	ptr_map = NULL;
	par_lst = NULL;
	if (ft_checkargc(argc) != -1)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (ft_error(0, 0));
		if ((ptr_map = ft_check_error(fd, ptr_map, par_lst)) == NULL)
			return (ft_error(fd, 1));
		close(fd);
		ptr_map->nb_tetri = ft_maplen(ptr_map);
		sqrt_size = ft_sqrt((ptr_map->nb_tetri) * 4);
		if ((tab = ft_firstalloc(sqrt_size)) == NULL)
			return (-1);
		tab = solve(ptr_map, sqrt_size, tab);
		ft_puttab(tab);
		ft_free_tab(tab);
		ft_free_ptr_map(ptr_map);
	}
	return (0);
}
