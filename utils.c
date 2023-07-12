/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:15:17 by yorlians          #+#    #+#             */
/*   Updated: 2023/03/24 00:37:13 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_doubleptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	incorrect_argument(void)
{
	errno = EINVAL;
	perror(NULL);
	exit(EINVAL);
}

void	close_and_wait(t_pipex *pipex, int *status)
{
	close(pipex -> pipefd[0]);
	close(pipex -> pipefd[1]);
	waitpid(pipex -> pid[0], status, 0);
	waitpid(pipex -> pid[1], status, 0);
}

void	free_and_exit(t_pipex *pipex, int exit_status)
{
	free_doubleptr(pipex -> path);
	free(pipex -> pid);
	free(pipex);
	exit (exit_status);
}

t_pipex	*init_pipex(char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(EXIT_FAILURE);
	pipex -> pid = malloc(2 * sizeof(pid_t));
	if (!pipex -> pid)
	{
		free(pipex);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipex -> pipefd) < 0)
	{
		free(pipex -> pid);
		free(pipex);
		exit (EXIT_FAILURE);
	}
	pipex -> path = find_path(envp);
	return (pipex);
}
