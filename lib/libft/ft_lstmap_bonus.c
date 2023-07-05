/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:13:28 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/29 17:09:27 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_privlstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

static void	ft_privlstclear(t_list **lst, void (*del)(void*))
{
	t_list	*iter;
	t_list	*aux;

	iter = *lst;
	while (iter != 0)
	{
		aux = iter->next;
		ft_privlstdelone(iter, del);
		iter = aux;
	}
	*lst = 0;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_first;
	t_list	*aux_new;

	if (lst == NULL)
		return (0);
	lst_first = (t_list *) malloc (sizeof(t_list));
	if (lst_first == NULL)
		return (0);
	aux_new = lst_first;
	aux_new -> content = f(lst->content);
	lst = lst -> next;
	while (lst != NULL)
	{
		aux_new -> next = (t_list *) malloc (sizeof(t_list));
		if (aux_new -> next == NULL)
		{
			ft_privlstclear(&lst_first, del);
			return (0);
		}
		(aux_new -> next)-> content = f(lst -> content);
		lst = lst -> next;
		aux_new = aux_new -> next;
	}
	aux_new ->next = NULL;
	return (lst_first);
}
