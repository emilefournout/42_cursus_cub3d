/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:58:32 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 18:06:02 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					cont;
	unsigned const char		*str;
	unsigned char			unsig_c;

	unsig_c = c;
	str = s;
	cont = 0;
	while (cont < n)
	{
		if (str[cont] == unsig_c)
			return (((void *) str) + cont);
		cont++;
	}
	if (cont == n)
		return (0);
	if (unsig_c == 0)
		return (((void *) str) + cont);
	return (0);
}
