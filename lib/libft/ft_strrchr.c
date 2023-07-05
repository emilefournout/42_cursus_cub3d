/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:59:40 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 17:59:50 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int		found;
	size_t	lastoc;
	size_t	cont;

	found = 0;
	cont = 0;
	while (s[cont] != 0)
	{
		if (s[cont] == (char) c)
		{
			lastoc = cont;
			if (!found)
				found = 1;
		}
		cont++;
	}
	if ((char) c == 0)
		return (((char *) s) + cont);
	if (found)
		return (((char *) s) + lastoc);
	return (0);
}
