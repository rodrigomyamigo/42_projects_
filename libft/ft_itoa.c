/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:38:05 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/29 04:14:49 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int c)
{
	if (c < 0)
		return (c * (-1));
	return (c);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		size;
	int		temp;

	size = 0;
	temp = n;
	while (temp != 0)
	{
		temp /= 10;
		size++;
	}
	if (n == 0)
		size++;
	ptr = (char *)malloc(((n < 0) + size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (n < 0)
		ptr[0] = '-';
	ptr[(n < 0) + size] = 0;
	while ((n < 0) + --size >= (n < 0))
	{
		ptr[(n < 0) + size] = ft_abs(n % 10) + 48;
		n /= 10;
	}
	return (ptr);
}
