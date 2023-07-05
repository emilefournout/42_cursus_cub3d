/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:51:14 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 16:20:08 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(int n)
{
	int	counter;

	if (n == 0)
		return (1);
	counter = 0;
	while (n != 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		negative;
	int		size;
	int		i;

	negative = (n < 0);
	size = ft_countdigits(n);
	res = (char *) malloc (size + negative + 1);
	if (res == NULL)
		return (res);
	res[size + negative] = 0;
	i = size + negative - 1;
	while (i >= negative)
	{
		if (negative)
			res[i] = '0' - (n % 10);
		else
			res[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	if (negative)
		res[0] = '-';
	return (res);
}
