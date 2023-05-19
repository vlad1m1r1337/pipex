/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:42:24 by vgribkov          #+#    #+#             */
/*   Updated: 2023/04/16 18:32:13 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_finder(char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = "PATH=";
	while (env[i])
	{
		if (*env[i] == 'P')
		{
			if (!(ft_strncmp(env[i], path, 5)))
				path = env[i];
		}
		i++;
	}
	return (path);
}

char	*true_path(char *argv, char **env)
{
	int				i;
	char			**res_split;
	char			**args;
	char			*path;

	if (access(argv, F_OK) == 0)
		return (argv);
	if (ft_strchr (argv, '/') != NULL)
		f_error();
	path = "PATH=";
	i = 0;
	args = ft_split(argv, ' ');
	path = path_finder(env);
	i = 0;
	res_split = ft_split(path, ':');
	fn_path(res_split, args[0]);
	while (res_split[i])
	{
		if (access(res_split[i], F_OK) == 0)
			return (res_split[i]);
		i++;
	}
	f_error();
	return (NULL);
}

void	close_2(int first, int second)
{
	if (first == -1 || second == -1)
	{
		perror("Failed close");
		exit(0);
	}
	close(first);
	close(second);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	close_all(t_variables *variables)
{
	close(variables -> outfile);
	close(variables -> infile);
	close(variables -> fd[1]);
	close(variables -> fd[0]);
}
