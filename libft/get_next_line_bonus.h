/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:15:08 by akosloff          #+#    #+#             */
/*   Updated: 2024/12/04 12:15:16 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define OPEN_MAX 1024

char	*get_next_line(int fd);
size_t	get_strlen(const char *s);
char	*get_strjoin(char *s1, char *s2);
char	*get_substr(char const *s, unsigned int start, size_t len);
char	*find_line(char *buffer);
char	*read_from_file(int fd, char *buffer);
char	*ft_strchr(const char *s, int c);
char	*clean_buffer(char *buffer, char *line);
char	*null_free(char *s1, char *s2);

#endif