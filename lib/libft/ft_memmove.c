/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:45:40 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 17:57:03 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overlaps(void *dst, const void *src, size_t len)
{
	size_t	src_min;
	size_t	dst_min;
	size_t	src_max;
	size_t	dst_max;

	src_min = (size_t) src;
	dst_min = (size_t) dst;
	src_max = src_min + len;
	dst_max = dst_min + len;
	return (dst_max >= src_max && src_min <= dst_min);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*strdst;
	char	*strsrc;
	size_t	cont;

	cont = 0;
	strdst = (char *) dst;
	strsrc = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (ft_overlaps(dst, src, len))
	{
		cont = len;
		while (cont > 0)
		{
			strdst[cont - 1] = strsrc[cont - 1];
			cont--;
		}
		return (dst);
	}
	while (cont < len)
	{
		strdst[cont] = strsrc[cont];
		cont++;
	}
	return (dst);
}
