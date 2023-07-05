/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:52:52 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 17:55:53 by josesanc         ###   ########.fr       */
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

size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	j = 0;
	destlen = ft_priv_strlen(dest);
	srclen = ft_priv_strlen(src);
	while (dest[i] != 0)
		i++;
	while (src[j] != 0 && i + 1 < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (nb <= destlen)
		return (srclen + nb);
	dest[i] = 0;
	return (srclen + destlen);
}
