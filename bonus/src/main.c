/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:23:41 by mtocu             #+#    #+#             */
/*   Updated: 2024/05/16 11:31:22 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	initiate(t_context *p, int argc, char **argv, char **envp)
{
	p->argv = argv;
	p->argc = argc;
	p->envp = envp;
}

void	ft_error(const char *message)
{
	perror(message);
	exit(1);
}

void	validate_args(t_context *p)
{
	if (p->argc < 5)
		ft_error("Too few arguments");
	p->filein = open(p->argv[1], O_RDONLY);
	if (access(p->argv[1], R_OK) == -1)
		ft_error("I can't access the first file");
	if (p->filein == -1)
		ft_error("The first file cannot be accessed");
	p->fileout = open(p->argv[p->argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (access(p->argv[p->argc - 1], W_OK) == -1)
		ft_error("The second file cannot be accessed");
	if (p->fileout == -1)
		ft_error("The second file cannot be accessed");
}

void	child_process2(t_context *p, int i, int *fd, int prev_fd)
{
	while (++i <= p->argc - 2)
	{
		if (pipe(fd) == -1)
			ft_error("pipe");
		p->pid = fork();
		if (p->pid == -1)
			ft_error("fork");
		if (p->pid == 0)
		{
			dup2(prev_fd, STDIN_FILENO);
			close(prev_fd);
			if (i != p->argc - 2)
				dup2(fd[1], STDOUT_FILENO);
			else
				dup2(p->fileout, STDOUT_FILENO);
			close(fd[0]);
			execute(p->argv[i], p->envp);
		}
		close(fd[1]);
		prev_fd = fd[0];
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_context	p;

	initiate(&p, argc, argv, envp);
	validate_args(&p);
	p.prev_fd = p.filein;
	child_process2(&p, 1, p.fd, p.prev_fd);
	waitpid(p.pid, NULL, 0);
	close(p.filein);
	close(p.fileout);
	return (0);
}
