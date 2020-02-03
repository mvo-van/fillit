/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:47:53 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/12/30 10:31:59 by smoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_calnei(t_lst_map *ptr_map, int nei, int c, int l)
{
	if (l != 0 && ptr_map->map[l - 1][c] == '#')
		nei++;
	if (l != 3 && ptr_map->map[l + 1][c] == '#')
		nei++;
	if (c != 0 && ptr_map->map[l][c - 1] == '#')
		nei++;
	if (c != 3 && ptr_map->map[l][c + 1] == '#')
		nei++;
	nei = nei - 1;
	return (nei);
}

int					ft_valid(t_lst_map *ptr_map)
{
	int			c;
	int			l;
	int			nei;
	int			nbr;

	l = 0;
	nei = 0;
	nbr = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (ptr_map->map[l][c] == '#')
			{
				nbr++;
				nei = ft_calnei(ptr_map, nei, c, l);
			}
			c++;
		}
		l++;
	}
	if (nbr != 4 || (nei != 2 && nei != 4))
		return (0);
	return (1);
}

static t_lst_map	*ft_new_map(t_lst_map *ptr_map)
{
	t_lst_map	*new;

	if (!(new = (t_lst_map *)malloc(sizeof(t_lst_map))))
		return (NULL);
	if (ptr_map == NULL)
		new->index = 1;
	else
		new->index = ptr_map->index + 1;
	new->next = NULL;
	new->x_min = 3;
	new->x_max = 0;
	new->y_min = 3;
	new->y_max = 0;
	new->x = 0;
	new->y = 0;
	return (new);
}

int					ft_tab_map(char *buff, t_lst_map *ptr_map, int count)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (buff[i] == '.' || buff[i] == '#')
		{
			ptr_map->map[count][i] = buff[i];
			if (buff[i] == '#' && i < ptr_map->x_min)
				ptr_map->x_min = i;
			if (buff[i] == '#' && i > ptr_map->x_max)
				ptr_map->x_max = i;
			if (buff[i] == '#' && count < ptr_map->y_min)
				ptr_map->y_min = count;
			if (buff[i] == '#' && count > ptr_map->y_max)
				ptr_map->y_max = count;
		}
		else
			return (0);
		i++;
	}
	if (buff[i] != '\n')
		return (0);
	return (1);
}

t_lst_map			*ft_check_error(int fd, t_lst_map *ptr_map,
		t_lst_map *par_lst)
{
	int			ret;

	ret = 1;
	while (ret)
	{
		if (ret > 0)
		{
			if (!(ptr_map))
			{
				ptr_map = ft_new_map(ptr_map);
				par_lst = ptr_map;
			}
			else
			{
				par_lst->next = ft_new_map(par_lst);
				par_lst = par_lst->next;
			}
			if (ft_checkret(par_lst, fd, &ret) == 0)
				return (0);
		}
	}
	return (ptr_map);
}
