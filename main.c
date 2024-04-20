/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:47 by mtocu             #+#    #+#             */
/*   Updated: 2024/04/20 11:34:04 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, fd);
		else
		{
			waitpid (pid1, NULL, 0);
			pid1 = fork();
			if (pid1 == -1)
				error();
			if (pid1 == 0)
				parent_process(argv, envp, fd);
		}
	}
	else
		ft_putstr_fd("Error: bad arguments\nEx: ./pipex f1 cmd1 cmd2 f2\n", 2);
	return (0);
}
