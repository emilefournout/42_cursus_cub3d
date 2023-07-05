/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:59:04 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 17:59:16 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			counter;
	int				res;

	counter = 0;
	res = 0;
	if (n == 0)
		return (0);
	while (!res && (s1[counter] != '\0' || s2[counter] != '\0') && counter < n)
	{
		res = ((unsigned char) s1[counter]) - ((unsigned char) s2[counter]);
		if (!res)
			counter++;
	}
	if (counter < n)
	{
		res = ((unsigned char)s1[counter]) - ((unsigned char) s2[counter]);
	}
	return (res);
}
