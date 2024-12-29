/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:54:20 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/28 23:07:05 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
		write(fd, "-", 1);
	if (n / 10 != 0)
		ft_putnbr_fd((n / 10) * ((n > 0) - (n < 0)), fd);
	c = (n % 10) * ((n > 0) - (n < 0)) + 48;
	write(fd, &c, 1);
}
