/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:57:27 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 17:57:28 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	counter;
	char	*dest_ptr;
	char	*src_ptr;

	dest_ptr = (char *)dst;
	src_ptr = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	counter = 0;
	while (counter < n)
	{
		dest_ptr[counter] = src_ptr[counter];
		counter++;
	}
	return (dst);
}
