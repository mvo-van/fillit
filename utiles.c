/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 01:59:47 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/01/04 01:59:51 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freetab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_delete(t_lst_map *ptr_map, char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == ptr_map->index + 'A' - 1)
				tab[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

int		ft_checkret(t_lst_map *par_lst, int fd, int *ret)
{
	char	buff[6];
	int		count;

	count = 0;
	while (count < 4 && *ret)
	{
		if (((*ret = read(fd, buff, 5)) < 5 || (*ret == 5 && buff[4]
						!= '\n')) || !(ft_tab_map(buff, par_lst, count)))
			return (0);
		count++;
	}
	if ((count == 4 && (((*ret = read(fd, buff, 1)) < 0) || (par_lst->index
						>= 26 && buff[0] != '\n'))) || !(ft_valid(par_lst)))
		return (0);
	return (1);
}

void	ft_freelst(t_lst_map *ptr_map)
{
	while (ptr_map)
	{
		free(ptr_map);
		ptr_map = ptr_map->next;
	}
}
