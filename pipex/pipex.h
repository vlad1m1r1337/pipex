/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:46:10 by vgribkov          #+#    #+#             */
/*   Updated: 2023/04/16 18:31:06 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_variables
{
	int	f1;
	int	f2;
	int	a;
	int	infile;
	int	outfile;
	int	fd[2];
	int	cc;
}				t_variables;

int		ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, int start, int len);

int		ft_strncmp(const char *s1, const char *s2, int n);

int		count_words(char const *s, char c);

char	**main_split(char const *s, char c);

char	**ft_split(char const *s, char c);

void	fn_path(char **res_split, char *argv);

char	*true_path(char *argv, char **env);

void	close_all(t_variables *variables);

void	close_2(int first, int second);

char	*path_finder(char **env);

void	open_files(t_variables *variables, char **argv, int argc);

char	*ft_strchr(const char *s, int c);

void	f_error(void);

#endif