/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:37:26 by vgribkov          #+#    #+#             */
/*   Updated: 2023/04/10 11:48:32 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*arr;
	int		j;
	int		i;

	str = (char *)s1;
	j = ft_strlen(str);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		i;
	int		j;
	int		step;

	if (!s1 || !s2)
		return (NULL);
	step = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	arr = (char *)malloc(i + j + 1);
	if (!arr)
		return (NULL);
	while (*s1)
		arr[step++] = *s1++;
	while (*s2)
		arr[step++] = *s2++;
	arr[step] = '\0';
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	if (count == 0)
	{
		words = (char **)malloc(1 * sizeof(char *));
		if (!words)
			return (NULL);
		words[0] = NULL;
		return (words);
	}
	words = main_split(s, c);
	if (!words)
		return (NULL);
	return (words);
}
