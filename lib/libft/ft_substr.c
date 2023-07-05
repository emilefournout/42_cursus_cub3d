/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:01:25 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 18:05:53 by josesanc         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_priv_strlen(s);
	if (start > size)
	{
		res = (char *) malloc (1);
		if (res == NULL)
			return (0);
		res[0] = 0;
		return (res);
	}
	if (start + len > size)
		res = (char *) malloc ((size - start) + 1);
	else
		res = (char *) malloc (len + 1);
	if (res == NULL)
		return (0);
	while (i < len && s[start] != 0)
		res[i++] = s[start++];
	res[i] = 0;
	return (res);
}
