/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:19:48 by kkrasnod          #+#    #+#             */
/*   Updated: 2024/12/28 21:50:46 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_rows(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i])
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	return (count);
}

static void	set_values(char **arr, int count, const char *s, char c)
{
	int	i;
	int	row;
	int	how_many;
	int	j;

	i = 0;
	row = -1;
	while (++row < count)
	{
		while (s[i] && s[i] == c)
			i++;
		how_many = 0;
		while (s[i] != c && s[i])
		{
			how_many++;
			i++;
		}
		arr[row] = (char *)malloc((how_many + 1) * sizeof(char));
		j = 0;
		while (how_many--)
			arr[row][j++] = s[i - how_many - 1];
		arr[row][j] = 0;
	}
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**arr;

	count = count_rows(s, c);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	set_values(arr, count, s, c);
	arr[count] = 0;
	return (arr);
}

// static char	**set_values(char **arr, int count, char sep, char *s)
//{
//	int	i;
//	int	j;
//	int	row;
//	int	size;
//	int	n;
//
//	n = 0;
//	i = -1;
//	row = 0;
//	while (++i < count) //(s[++i]) //++i < count)
//	{
//		if (s[i] == sep && s[i + 1] != sep && s[i + 1])
//		{
//			j = i + 1;
//			while (s[j] != sep)
//				j++;
//			size = j - i;
//			arr[row] = (char *)malloc(size * sizeof(char));
//			if (!arr[row])
//				return (NULL);
//			n = 0;
//			while (n < size)
//			{
//				arr[row][n++] = s[++i];
//			}
//			arr[row++][n] = 0;
//		}
//	}
//	return (arr);
//}