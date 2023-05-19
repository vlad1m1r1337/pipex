/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_strchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:22:52 by vgribkov          #+#    #+#             */
/*   Updated: 2023/04/16 18:31:22 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr(const char *s, int c)
{
	char	l;

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

void	f_error(void)
{
	perror("Error");
	exit(0);
}
