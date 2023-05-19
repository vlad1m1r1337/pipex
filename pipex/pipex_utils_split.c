/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:40:26 by vgribkov          #+#    #+#             */
/*   Updated: 2023/04/05 13:33:52 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	size_t	c;

	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	c = len;
	str = malloc(len + 1);
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

int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
		s++;
		if (*s == '\0')
			return (count);
		while (*s != c && *s != '\0')
			s++;
		count++;
	}
	return (count);
}

char	**main_split(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	words = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[i] != c && s[i])
			i++;
		if (i > k)
		{
			words[j] = ft_substr(s, k, i - k);
			j++;
		}
	}
	words[j] = NULL;
	return (words);
}
