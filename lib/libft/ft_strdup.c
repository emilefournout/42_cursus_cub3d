/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:50:01 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 18:03:05 by josesanc         ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*ptr;

	i = 0;
	size = ft_priv_strlen(s1);
	ptr = (char *) malloc (size + 1);
	if (ptr == 0)
		return (0);
	while (i < size)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
