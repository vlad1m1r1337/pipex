/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:01:28 by vgribkov          #+#    #+#             */
/*   Updated: 2023/04/16 14:23:51 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "get_next_line.h"

int	here_doc_check(char *argv)
{
	if (ft_strncmp(argv, "here_doc", 8) == 0
		&& ft_strlen(argv) == 8)
		return (1);
	return (0);
}

void	close_with_check(int fd)
{
	if (fd == -1)
	{
		perror("Failed close");
		exit(0);
	}
	close(fd);
}

void	here_doc(t_variables *variables, char *lim)
{
	char	*str;

	variables -> here_doc = open("here_doc", O_RDWR | O_CREAT, 0644);
	while (1)
	{
		write(1, "pipe heredoc> ", 15);
		str = get_next_line(0);
		if (!str || !*str)
		{
			free(str);
			write(1, "\n", 1);
			break ;
		}
		if (ft_strncmp(str, lim, ft_strlen(str) - 1) == 0
			&& ft_strncmp(str, lim, ft_strlen(lim)) == 0)
		{
			free(str);
			break ;
		}
		write(variables -> here_doc, str, ft_strlen(str));
		free(str);
	}
	close_with_check(variables -> here_doc);
}
