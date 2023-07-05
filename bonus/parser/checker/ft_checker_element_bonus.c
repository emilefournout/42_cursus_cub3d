/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_element_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:13:12 by efournou          #+#    #+#             */
/*   Updated: 2023/02/08 19:24:39 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static bool	ft_check_name_elem(const char two_first_char_of_line[2])
{
	if (!((two_first_char_of_line[0] == 'N' && two_first_char_of_line[1] == 'O')
			|| (two_first_char_of_line[0] == 'S'
				&& two_first_char_of_line[1] == 'O')
			|| (two_first_char_of_line[0] == 'E'
				&& two_first_char_of_line[1] == 'A')
			|| (two_first_char_of_line[0] == 'W'
				&& two_first_char_of_line[1] == 'E')
			|| (two_first_char_of_line[0] == 'F')
			|| (two_first_char_of_line[0] == 'C')))
	{
		if (!((two_first_char_of_line[0] == 'D'
					&& two_first_char_of_line[1] == 'O')
				|| (two_first_char_of_line[0] == 'S'
					&& two_first_char_of_line[1] == 'P')))
			return (false);
	}
	return (true);
}

void	ft_fill_tfc(char tfc[2], int nci, t_list *e)
{
	tfc[0] = ((char *)(e->content))[nci];
	tfc[1] = ((char *)(e->content))[nci + 1];
}

void	*ft_c_txtr(char *n, t_list *e)
{
	int		nci;
	char	tfc[2];

	while (1)
	{
		nci = ft_space_element(e->content);
		if (nci == -1)
		{
			e = e->next;
			continue ;
		}
		if (nci == -2)
			return ((void *)1);
		ft_fill_tfc(tfc, nci, e);
		if (ft_check_name_elem(tfc) == false && tfc[0] == '1')
			return ((void *)2);
		else if (ft_check_name_elem(tfc) == false)
			return ((void *)1);
		if (tfc[0] == n[0] && tfc[1] == n[1] && ft_c_txtr(n,
				e->next) != (void *)2)
			return ((void *)1);
		else if (tfc[0] == n[0] && tfc[1] == n[1])
			return (&((char *)(e->content))[nci + 2]);
		e = e->next;
	}
}

void	*ft_check_color(char *n, t_list *e)
{
	int		nci;
	char	tfc[2];

	while (1)
	{
		nci = ft_space_element(e->content);
		if (nci == -1)
		{
			e = e->next;
			continue ;
		}
		if (nci == -2)
			return ((void *)1);
		tfc[0] = ((char *)(e->content))[nci];
		tfc[1] = ((char *)(e->content))[nci + 1];
		if (ft_check_name_elem(tfc) == false && tfc[0] == '1')
			return ((void *)2);
		else if (ft_check_name_elem(tfc) == false)
			return ((void *)1);
		if (tfc[0] == n[0] && ft_check_color(n, e->next) != (void *)2)
			return ((void *)1);
		else if (tfc[0] == n[0])
			return (&((char *)(e->content))[nci + 1]);
		e = e->next;
	}
}
