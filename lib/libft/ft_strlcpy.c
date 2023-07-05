/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:51:48 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 17:55:49 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_priv_strlen(const char *s)
{
	int	cont;

	cont = 0;
	while (s[cont] != 0)
		cont++;
	return (cont);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	copied;

	copied = 0;
	if (size != 0)
	{
		while (copied < size - 1 && src[copied] != '\0')
		{
			dst[copied] = src[copied];
			copied++;
		}
		dst[copied] = '\0';
	}
	return (ft_priv_strlen(src));
}
