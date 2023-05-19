/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:49:50 by vgribkov          #+#    #+#             */
/*   Updated: 2023/04/08 17:17:48 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *str)
{
	char	*arr;
	int		j;
	int		i;

	j = ft_strlen_gnl(str);
	arr = (char *)malloc(j + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < j)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	l;

	if (!s)
		return (NULL);
	l = (char)c;
	while (*s)
	{
		if (*s == l)
			return ((char *)s);
		s++;
	}
	if (*s == l)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*arr;
	int		i;
	int		j;
	int		step;

	if (!s1)
		return (ft_strdup_gnl(s2));
	step = 0;
	i = ft_strlen_gnl(s1);
	j = ft_strlen_gnl(s2);
	arr = (char *)malloc(i + j + 1);
	if (!arr)
		return (NULL);
	while (*s1)
		arr[step++] = *s1++;
	if (!s2)
		return (arr);
	while (*s2)
		arr[step++] = *s2++;
	arr[step] = '\0';
	return (arr);
}

char	*ft_substr_gnl(char *s, int start, int len)
{
	char	*str;
	int		c;

	if (len > ft_strlen_gnl(s) - start)
		len = ft_strlen_gnl(s) - start;
	if (start > ft_strlen_gnl(s))
		return (ft_strdup_gnl(""));
	c = len;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (*s && start > 0)
	{
		s++;
		start--;
	}
	while (*s && len > 0)
	{
		*str++ = *s++;
		len--;
	}
	*str = '\0';
	str -= c;
	return (str);
}
