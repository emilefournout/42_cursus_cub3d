/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:07:27 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 17:54:28 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*aux;
	size_t	counter;
	size_t	mult;

	counter = 0;
	mult = count * size;
	ptr = malloc(mult);
	if (ptr == 0)
		return (ptr);
	aux = (char *)ptr;
	while (counter < mult)
	{
		aux[counter] = '\0';
		counter++;
	}
	return (ptr);
}
