/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:46:28 by vgribkov          #+#    #+#             */
/*   Updated: 2023/05/19 17:21:54 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "get_next_line.h"

int	open_files_check(t_variables *variables, char **argv, int argc)
{
	if (here_doc_check(argv[1]))
	{
		here_doc(variables, argv[2]);
		variables -> infile = open("here_doc", O_RDWR, 0777);
		variables -> outfile = open(argv[argc - 1],
				O_RDWR | O_CREAT | O_APPEND, 0777);
	}
	if (!(here_doc_check(argv[1])))
	{
		variables -> infile = open(argv[1], O_RDWR, 0777);
		variables -> outfile = open(argv[argc - 1],
				O_RDWR | O_CREAT | O_TRUNC, 0777);
	}
	if (here_doc_check(argv[1]))
		return (1);
	return (0);
}

void	dup2_2(int first, int second, int third, int fourth)
{
	if (first == -1 || second == -1 || third == -1 || fourth == -1)
	{
		perror("Failed dup2");
		exit(0);
	}
	dup2(first, second);
	dup2(third, fourth);
}

void	piping(t_variables *variables, char **argv, char **env, int i)
{
	char	**args;

	variables -> f1 = fork();
	if (variables -> f1 == 0)
	{
		args = ft_split(argv[i], ' ');
		if (i == 2)
			dup2_2(variables -> infile, STDIN_FILENO,
				variables -> fd[i - 2][1], STDOUT_FILENO);
		else if (i == 3 && here_doc_check(argv[1]))
			dup2_2(variables -> here_doc, STDIN_FILENO,
				variables -> fd[i - 2][1], STDOUT_FILENO);
		else if (i == variables -> cc)
			dup2_2(variables -> outfile, STDOUT_FILENO,
				variables -> fd[i - 3][0], STDIN_FILENO);
		else
			dup2_2(variables -> fd[i - 2][1], STDOUT_FILENO,
				variables -> fd[i - 3][0], STDIN_FILENO);
		close_all(variables);
		execve(true_path(argv[i], env), args, env);
	}
}

void	do_pipes(t_variables *variables)
{
	int	i;

	i = 0;
	while (i < variables -> cc)
		pipe (variables -> fd [i++]);
}

int	main(int argc, char **argv, char **env)
{
	t_variables	variables;
	int			i;

	if (argc < 5)
	{
		perror("Wrong arguments");
		exit(0);
	}
	variables.cc = argc - 2;
	i = 2;
	i += open_files_check(&variables, argv, argc);
	do_pipes(&variables);
	while (i < argc - 1)
		piping(&variables, argv, env, i++);
	close_all(&variables);
	while (wait(NULL) != -1)
		;
	unlink("here_doc");
}
