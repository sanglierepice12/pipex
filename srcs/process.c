/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:09:51 by gostr             #+#    #+#             */
/*   Updated: 2024/03/25 17:12:32 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	_child_process(t_struct *var, char **argv)
{
	_check_cmd(var, argv, 1);
	if (dup2(var->fd, STDIN_FILENO) < 0)
		exit(EXIT_FAILURE);
	if (dup2(var->pipe_fd[1], STDOUT_FILENO) < 0)
		exit(EXIT_FAILURE);
	close(var->pipe_fd[1]);
	close(var->pipe_fd[0]);
	close(var->fd);
	if (var->cmd1)
		execve(var->cmd1[0], var->cmd1, var->path);
	_free_things(var);
	perror("Command not found\n");
	exit(EXIT_FAILURE);
}

void	_second_child_process(t_struct *var, char **argv)
{
	_check_cmd(var, argv, 0);
	if (dup2(var->pipe_fd[0], STDIN_FILENO) < 0)
		exit(EXIT_FAILURE);
	if (dup2(var->fd2, STDOUT_FILENO) < 0)
		exit(EXIT_FAILURE);
	close(var->fd2);
	close(var->pipe_fd[0]);
	close(var->pipe_fd[1]);
	if(var->cmd2)
		execve(var->cmd2[0], var->cmd2, var->path);
	_free_things(var);
	perror("Error\n");
	exit(EXIT_FAILURE);
}
