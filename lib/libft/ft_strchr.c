/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:44:59 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 18:56:50 by josesanc         ###   ########.fr       */
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

char	*ft_strchr(const char	*s, int c)
{
	size_t	cont;
	char	char_c;

	char_c = c;
	cont = 0;
	if (char_c == 0)
		return (((char *)s) + ft_priv_strlen(s));
	while (s[cont] != 0)
	{
		if (s[cont] == char_c)
			return (((char *)s) + cont);
		cont++;
	}
	return (0);
}
