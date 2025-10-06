/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 07:31:24 by msidry            #+#    #+#             */
/*   Updated: 2025/10/04 22:39:20 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	int	idx;

	idx = 0;
	if (!str1 && str2)
		return (-(*str2));
	if (str1 && !str2)
		return (*str1);
	if (!str1 && !str2)
		return (0);
	while (str1[idx] && str2[idx] && str1[idx] == str2[idx])
		idx++;
	return ((unsigned char)str1[idx] - (unsigned char)str2[idx]);
}
