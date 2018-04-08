/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 19:21:16 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/08 19:22:39 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_ctoa_min(void)
{
	char	*tab;

	if (!(tab = (char *)malloc(sizeof(*tab) * (5))))
		return (0);
	tab[0] = '-';
	tab[1] = '1';
	tab[2] = '2';
	tab[3] = '8';
	tab[4] = '\0';
	return (tab);
}

static char	*ft_ctoa_malloc(char n, int j)
{
	char	*tab;

	if (!(tab = (char *)malloc(sizeof(*tab) * (j + 1))))
		return (0);
	tab[j] = '\0';
	if (n == 0)
		tab[0] = 48;
	if (n < 0)
	{
		tab[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		tab[j - 1] = (n % 10) + 48;
		n = n / 10;
		j--;
	}
	return (tab);
}

char		*ft_ctoa(char n)
{
	char	i;
	int		j;

	i = n;
	j = 0;
	if (n == -128)
		return (ft_ctoa_min());
	else if (i <= 0)
	{
		i = -i;
		j++;
	}
	while (i > 0)
	{
		i = i / 10;
		j++;
	}
	return (ft_ctoa_malloc(n, j));
}
