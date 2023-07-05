/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josesanc <josesanc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:09:48 by josesanc          #+#    #+#             */
/*   Updated: 2022/09/23 19:01:25 by josesanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_priv_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static size_t	ft_priv_strlen(const char *s)
{
	int	cont;

	cont = 0;
	while (s[cont] != 0)
		cont++;
	return (cont);
}

static void	ft_priv_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_priv_strlen(s));
}

static void	ft_putnbr_fd_rec(int n, int fd)
{
	char	towrite;

	if (n != 0)
	{
		if (n < 0)
			towrite = '0' - (n % 10);
		else
			towrite = '0' + (n % 10);
		ft_putnbr_fd_rec(n / 10, fd);
		ft_priv_putchar_fd(towrite, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		ft_priv_putstr_fd("0", fd);
		return ;
	}
	if (n < 0)
		ft_priv_putstr_fd("-", fd);
	ft_putnbr_fd_rec(n, fd);
}
