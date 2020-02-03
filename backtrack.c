/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 07:23:22 by smoreno-          #+#    #+#             */
/*   Updated: 2018/12/30 09:53:59 by smoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		test_pos(t_lst_map *ptr_map, char **tab, int sqrt_size)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i + ptr_map->y_min <= ptr_map->y_max)
	{
		while (j + ptr_map->x_min <= ptr_map->x_max)
		{
			if (ptr_map->map[i + ptr_map->y_min][j + ptr_map->x_min] == '#'
					&& (ptr_map->x + j >= sqrt_size || ptr_map->y + i
						>= sqrt_size))
				return (0);
			if (ptr_map->map[i + ptr_map->y_min][j + ptr_map->x_min] == '#' &&
					ft_isalpha(tab[ptr_map->y + i][ptr_map->x + j]) == 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static char		**letters(t_lst_map *ptr_map, char **tab)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i + ptr_map->y_min <= ptr_map->y_max)
	{
		while (j + ptr_map->x_min <= ptr_map->x_max)
		{
			if (ptr_map->map[i + ptr_map->y_min][j + ptr_map->x_min] == '#')
				tab[ptr_map->y + i][ptr_map->x + j] = ptr_map->index + 'A' - 1;
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

static int		place(t_lst_map *ptr_map, int sqrt_size, char **tab)
{
	if (ptr_map != NULL)
	{
		while (ptr_map->x * ptr_map->y < sqrt_size * sqrt_size)
		{
			if ((test_pos(ptr_map, tab, sqrt_size)) == 1)
			{
				tab = letters(ptr_map, tab);
				if (place(ptr_map->next, sqrt_size, tab) == 1)
					return (1);
				tab = ft_delete(ptr_map, tab);
			}
			if (ptr_map->x < sqrt_size)
				ptr_map->x++;
			else
			{
				ptr_map->x = 0;
				ptr_map->y++;
			}
		}
		ptr_map->x = 0;
		ptr_map->y = 0;
		return (0);
	}
	return (1);
}

static char		**ft_incrasetab(char **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	ft_freetab(tab);
	if (!(tab = (char **)malloc(sizeof(char *) * (size + 2))))
		return (0);
	while (i < size)
	{
		if (!(tab[i] = ft_strnew(size + 1)))
		{
			free(tab);
			return (0);
		}
		j = 0;
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char			**solve(t_lst_map *ptr_map, int sqrt_size, char **tab)
{
	while (place(ptr_map, sqrt_size, tab) == 0)
	{
		sqrt_size++;
		ptr_map->x = 0;
		ptr_map->y = 0;
		tab = ft_incrasetab(tab, sqrt_size);
	}
	return (tab);
}
