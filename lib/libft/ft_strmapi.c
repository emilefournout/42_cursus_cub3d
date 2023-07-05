/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:42:59 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 18:57:25 by josesanc         ###   ########.fr       */
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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	char			*res;

	res = (char *) malloc (ft_priv_strlen(s) + 1);
	if (res == NULL)
		return (0);
	counter = 0;
	while (s[counter] != 0)
	{
		res[counter] = f(counter, s[counter]);
		counter++;
	}
	res[counter] = 0;
	return (res);
}
