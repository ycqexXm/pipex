/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlians <yorlians@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:10:42 by yorlians          #+#    #+#             */
/*   Updated: 2023/03/24 00:37:23 by yorlians         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./Libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex
{
	int		inputfd;
	int		outputfd;
	int		pipefd[2];
	pid_t	*pid;
	char	**path;
}	t_pipex;

//	main functions
char	**find_path(char **envp);
char	*get_command(t_pipex *pipex, char **argument);
void	child(t_pipex *pipex, char **argv, char **envp, int i);
void	piping(t_pipex *pipex, char **argv, int i);

//	utils
void	free_doubleptr(char **ptr);
void	incorrect_argument(void);
void	close_and_wait(t_pipex *pipex, int *status);
void	free_and_exit(t_pipex *pipex, int exit_status);
t_pipex	*init_pipex(char **envp);

#endif