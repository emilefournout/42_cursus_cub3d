/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:56:23 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 18:03:14 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	towrite;
	size_t			cont;

	cont = 0;
	towrite = c;
	str = b;
	while (cont < len)
	{
		str[cont] = towrite;
		cont++;
	}
	return (b);
}
