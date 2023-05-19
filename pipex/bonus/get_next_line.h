/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:49:39 by vgribkov          #+#    #+#             */
/*   Updated: 2023/04/10 11:54:04 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);

int		ft_strlen_gnl(const char *str);

char	*ft_strchr_gnl(const char *s, int c);

char	*ft_strjoin_gnl(char *s1, char *s2);

char	*ft_strdup_gnl(char *s1);

char	*ft_substr_gnl(char *s, int start, int len);

#endif