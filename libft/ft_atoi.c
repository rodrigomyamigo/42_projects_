/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 00:10:10 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/21 00:28:06 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *a)
{
	int	i;
	int	result;
	int	value;

	value = 1;
	i = 0;
	result = 0;
	while (a[i] >= 13 && a[i] <= 13)
		i++;
	if (a[i] == '-')
	{
		value = -1;
		i++;
	}
	else if (a[i] == '+')
		i++;
	while (ft_isdigit(a[i]))
	{
		result = value * (10 * result + (a[i] - 48));
	}
	return (result);
}
