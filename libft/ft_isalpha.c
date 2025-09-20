/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:08:27 by msidry            #+#    #+#             */
/*   Updated: 2024/10/24 03:03:49 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_isupper(int n);
static	int	ft_islower(int n);

int	ft_isalpha(int n)
{
	return (ft_isupper(n) || ft_islower(n));
}

static	int	ft_isupper(int n)
{
	return (n >= 65 && n <= 90);
}

static	int	ft_islower(int n)
{
	return (n >= 97 && n <= 122);
}
