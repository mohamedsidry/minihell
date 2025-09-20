/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 01:09:09 by msidry            #+#    #+#             */
/*   Updated: 2024/11/04 01:44:51 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reco_write(long ln, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	reco_write(ln, fd);
}

void	reco_write(long ln, int fd)
{
	if (ln >= 10)
		reco_write(ln / 10, fd);
	ft_putchar_fd(ln % 10 + 48, fd);
}
