/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:43:23 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 17:58:24 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			counter;
	int				res;

	counter = 0;
	res = 0;
	if (n == 0)
		return (0);
	while (!res && counter < n)
	{
		res = ((unsigned char *) s1)[counter] - ((unsigned char *) s2)[counter];
		if (!res)
			counter++;
	}
	if (res)
		return (res);
	if (counter < n)
		res = ((unsigned char *) s1)[counter] - ((unsigned char *) s2)[counter];
	return (res);
}
