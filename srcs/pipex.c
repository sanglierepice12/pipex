/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:09:51 by gostr             #+#    #+#             */
/*   Updated: 2024/03/25 17:12:32 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	_process(t_struct *var, char **argv)
{
	if (pipe(var->pipe_fd) == -1)
		perror("Pipe failed");
	var->fd = open(argv[1], O_RDONLY);
	if (var->fd == -1)
		perror("Invalid in-file");
	var->pid = fork();
	if (var->pid == -1)
		perror("Pid failed");
	if (var->pid == 0)
		_child_process(var, argv);
	var->fd2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (var->fd2 == -1)
		perror("Invalid out-file");
	var->pid2 = fork();
	if (var->pid2 == -1)
		perror("Pid failed");
	if (var->pid2 == 0)
		_second_child_process(var, argv);
	close(var->pipe_fd[0]);
	close(var->pipe_fd[1]);
	waitpid(var->pid, 0, 0);
	waitpid(var->pid2, 0, 0);
}

int	main(int arc, char **argv, char **env)
{
	t_struct	*var;

	if (arc != 5)
		exit(EXIT_FAILURE);
	var = ft_calloc(1, sizeof(t_struct));
	if (!var)
		exit(EXIT_FAILURE);
	_init_path(var, env);
	_process(var, argv);
	_free_things(var);
	return (EXIT_SUCCESS);
}
