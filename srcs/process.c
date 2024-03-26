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

void	_child_process(t_struct *var, char **env)
{
	if (dup2(var->fd, STDIN_FILENO) < 0)
		exit(EXIT_FAILURE);
	printf("var-> %s\n", var->cmd1[0]);

	dup2(var->pipe_fd[1], STDOUT_FILENO);
	close(var->pipe_fd[0]);
	close(var->fd);
	execve(var->cmd1[0], var->cmd1, env);
	exit(EXIT_FAILURE);
}
