/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:46:28 by vgribkov          #+#    #+#             */
/*   Updated: 2023/04/16 17:58:12 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_variables *variables, char **argv, int argc)
{
	variables -> infile = open(argv[1], O_RDWR, 0777);
	variables -> outfile = open(argv[argc - 1],
			O_RDWR | O_CREAT | O_TRUNC, 0777);
}

void	size_check(int argc)
{
	if (argc != 5)
	{
		perror("Wrong arguments");
		exit(0);
	}
}

void	dup2_check(int fd1, int fd2)
{
	if (fd1 == -1 || fd2 == -1)
	{
		perror("open");
		exit(0);
	}
	dup2(fd1, fd2);
}

void	piping(t_variables *variables, char **argv, char **env, int i)
{
	char	**args;

	variables -> f1 = fork();
	if (variables -> f1 == 0)
	{
		if (i == 2)
		{
			dup2_check(variables -> infile, STDIN_FILENO);
			dup2_check(variables -> fd[1], STDOUT_FILENO);
			args = ft_split(argv[i], ' ');
			close_all(variables);
			execve(true_path(argv[i], env), args, env);
		}
		else if (i == 3)
		{
			dup2_check(variables -> outfile, STDOUT_FILENO);
			dup2_check(variables -> fd[0], STDIN_FILENO);
			args = ft_split(argv[i], ' ');
			close_all(variables);
			execve(true_path(argv[i], env), args, env);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	t_variables	variables;
	int			i;

	variables.cc = argc - 3;
	i = 2;
	size_check(argc);
	open_files(&variables, argv, argc);
	pipe(variables.fd);
	while (i < 4)
		piping(&variables, argv, env, i++);
	close_2(variables.infile, variables.outfile);
	close_2(variables.fd[1], variables.fd[0]);
	while (wait(NULL) != -1)
		;
}
