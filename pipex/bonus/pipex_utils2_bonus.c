/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:42:24 by vgribkov          #+#    #+#             */
/*   Updated: 2023/04/16 18:33:54 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	fn_path(char **res_split, char *argv)
{
	int		i;
	char	*temp;

	i = 0;
	while (res_split[i])
	{
		temp = res_split[i];
		res_split[i] = ft_strjoin(res_split[i], "/");
		res_split[i] = ft_strjoin(res_split[i], argv);
		i++;
	}
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
	int	i;

	i = 0;
	while (i < variables -> cc)
	{
		close(variables -> fd[i][0]);
		close(variables -> fd[i][1]);
		i++;
	}
	close(variables -> infile);
	close(variables -> outfile);
}
