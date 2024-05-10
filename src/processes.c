/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:50:58 by mtocu             #+#    #+#             */
/*   Updated: 2024/05/09 13:54:31 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	char	**paths;
	int		i;
	char	*part_p_with_slash;

	i = 0;
	while (envp[i] && ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_p_with_slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_p_with_slash, cmd);
		free(part_p_with_slash);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}

void	child_process(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY);
	if (access(argv[1], W_OK) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (filein == -1)
		error();
	dup2(filein, STDIN_FILENO); // read from file
	dup2(fd[1], STDOUT_FILENO); //writing in 1
	close(filein);
	close(fd[0]);
	close(fd[1]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (access(argv[4], W_OK) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO); // read from 0
	dup2(fileout, STDOUT_FILENO); // writing in the file
	close(fileout);
	close(fd[0]);
	close(fd[1]);
	execute(argv[3], envp);
}
