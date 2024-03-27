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

void	_check_cmd(t_struct *var, char **argv)
{
	var->cmd1 = ft_split(argv[2], 32);
	if (access(argv[2], F_OK) && access(argv[2], X_OK))
		var->cmd1 = _init_cmd(var->cmd1, var);
	var->cmd2 = ft_split(argv[3], 32);
	if (access(argv[3], F_OK) && access(argv[3], X_OK))
		var->cmd2 = _init_cmd(var->cmd2, var);
}

void	_process(t_struct *var, char **argv, char **env)
{
	_check_cmd(var, argv);
	if (pipe(var->pipe_fd) == -1)
		exit(EXIT_FAILURE);
	var->fd = open(argv[1], O_RDONLY);
	if (var->fd == -1)
		exit(EXIT_FAILURE);
	var->pid = fork();
	if (var->pid == -1)
		exit(EXIT_FAILURE);
	if (var->pid == 0)
		_child_process(var, env);
	var->fd2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (var->fd2 == -1)
		perror("bite\n");
	var->pid2 = fork();
	if (var->pid2 == -1)
		exit(EXIT_FAILURE);
	if (var->pid2 == 0)
		_second_child_process(var, env);
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
	var = calloc(1, sizeof(t_struct));
	_init_path(var, env);
	_process(var, argv, env);
	_free_things(var);
	return (EXIT_SUCCESS);
}
