/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:46:10 by vgribkov          #+#    #+#             */
/*   Updated: 2023/04/16 18:40:24 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	int	here_doc;
	int	fd[1000][2];
	int	cc;
}				t_variables;

int		ft_strlen(const char *str);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, int start, int len);

int		ft_strncmp(const char *s1, const char *s2, int n);

int		count_words(char const *s, char c);

char	**main_split(char const *s, char c);

char	**ft_split(char const *s, char c);

void	fn_path(char **res_split, char *argv);

char	*true_path(char *argv, char **env);

void	close_all(t_variables *variables);

char	*path_finder(char **env);

int		open_files_check(t_variables *variables, char **argv, int argc);

void	here_doc(t_variables *variables, char *lim);

int		here_doc_check(char *argv);

char	*ft_strchr(const char *s, int c);

void	f_error(void);

#endif