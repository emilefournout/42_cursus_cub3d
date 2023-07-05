/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:02:37 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 18:56:58 by josesanc         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	counterx;
	size_t	countery;
	char	*res;

	size = ft_priv_strlen(s1) + ft_priv_strlen(s2) + 1;
	res = (char *) malloc(size);
	if (res == NULL)
		return (NULL);
	counterx = 0;
	countery = 0;
	while (s1[counterx] != 0)
	{
		res[counterx] = s1[counterx];
		counterx++;
	}
	while (s2[countery] != 0)
	{
		res[(counterx) + countery] = s2[countery];
		countery++;
	}
	res[counterx + countery] = 0;
	return (res);
}
