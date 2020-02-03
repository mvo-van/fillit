/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 05:44:05 by smoreno-          #+#    #+#             */
/*   Updated: 2019/01/04 02:08:36 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <fcntl.h>

typedef struct			s_lst_map
{
	int					fd;
	int					nb_tetri;
	int					index;
	char				map[4][4];
	int					x_min;
	int					x_max;
	int					y_min;
	int					y_max;
	int					x;
	int					y;
	struct s_lst_map	*next;
}						t_lst_map;

void					ft_free_tab(char **tab);
int						ft_sqrt(int nb);
void					ft_free_ptr_map(t_lst_map *ptr_map);
int						ft_valid(t_lst_map *ptr_map);
int						ft_tab_map(char *buff, t_lst_map *ptr_map, int comp);
t_lst_map				*ft_check_error(int fd, t_lst_map *ptr_map,
		t_lst_map *par_lst);
void					ft_freetab(char **tab);
int						ft_checkret(t_lst_map *par_lst, int fd, int *ret);
char					**ft_delete(t_lst_map *ptr_map, char **tab);
char					**solve(t_lst_map *ptr_map, int sqrt_size, char **tab);
void					ft_freelst(t_lst_map *ptr_map);

#endif
