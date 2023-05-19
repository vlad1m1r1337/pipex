/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:46:18 by vgribkov          #+#    #+#             */
/*   Updated: 2023/04/10 11:49:26 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *cash)
{
	int		ret;
	char	buf[BUFFER_SIZE + 1];
	char	*temp;

	ret = 1;
	while (!ft_strchr_gnl(cash, '\n') && ret > 0)
	{
		ret = read (fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free (cash);
			free (temp);
			return (NULL);
		}
		buf[ret] = '\0';
		temp = cash;
		cash = ft_strjoin_gnl(cash, buf);
		free (temp);
	}
	return (cash);
}

char	*rebuffer(char *cash)
{
	char	*temp;
	int		len;

	if (ft_strchr_gnl(cash, '\n'))
	{
		temp = cash;
		len = ft_strlen_gnl(ft_strchr_gnl(cash, '\n') + 1);
		cash = ft_substr_gnl(cash, ft_strlen_gnl(cash) - len, len);
		free (temp);
		temp = NULL;
	}
	else
	{
		free(cash);
		return (NULL);
	}
	return (cash);
}

char	*ft_out(char *cash)
{
	char	*out;
	int		lk;

	lk = ft_strlen_gnl(cash);
	if (ft_strchr_gnl(cash, '\n'))
		out = ft_substr_gnl(cash, 0,
				lk - ft_strlen_gnl(ft_strchr_gnl(cash, '\n') + 1));
	else
		out = ft_strdup_gnl(cash);
	return (out);
}

char	*get_next_line(int fd)
{
	char static	*cash = NULL;
	char		*out;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	cash = read_line(fd, cash);
	if (cash[0] == '\0')
	{
		free(cash);
		cash = NULL;
		return (NULL);
	}
	out = ft_out(cash);
	cash = rebuffer(cash);
	return (out);
}
