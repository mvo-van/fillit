/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 01:34:16 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/01/04 02:08:08 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb == 0 || nb == 1)
		return (nb);
	while (i * i <= nb && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}

void	ft_free_ptr_map(t_lst_map *ptr_map)
{
	t_lst_map	*par_lst;

	while (ptr_map)
	{
		par_lst = ptr_map->next;
		free(ptr_map);
		ptr_map = par_lst;
	}
}
