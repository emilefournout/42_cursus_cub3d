/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:26:01 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/29 17:08:26 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_privlstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (1)
	{
		if (lst -> next == NULL)
			return (lst);
		else
			lst = lst -> next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*where_to_add;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	where_to_add = ft_privlstlast(*lst);
	if (where_to_add == NULL)
		return ;
	where_to_add->next = new;
}
