/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:50:01 by mtocu             #+#    #+#             */
/*   Updated: 2024/04/19 18:31:12 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

# define PROCESS_NUM 2

// typedef struct s_pipex
// {
// 	int		in_fd;
// 	int		out_fd;
// 	int		here_doc;
// 	char	**cmd_paths;
// 	char	***cmd_args;
// 	int		cmd_count;
// }			t_pipex;

char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

void	error(void);
void	child_process(char **argv, char **envp, int *fd);
void	parent_process(char **argv, char **envp, int *fd);
void	execute(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);

#endif
