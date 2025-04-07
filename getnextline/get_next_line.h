/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkrasnod <kkrasnod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:07:50 by kkrasnod          #+#    #+#             */
/*   Updated: 2025/04/07 16:09:29 by kkrasnod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

// int		open_file(const char *fd); // DO USUNIECIA
char	*clean_stash(char *stash);
char	*fill_and_find_newline(int fd, char *stash);
char	*join_and_free(char *s1, char *s2);
char	*return_line(char *stash);
char	*get_next_line(int fd);

//_utils
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif