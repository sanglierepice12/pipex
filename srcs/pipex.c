/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:26:28 by gsuter            #+#    #+#             */
/*   Updated: 2024/03/25 15:42:25 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	_init_things(t_struct *var, char **argv, char **env)
{
	if (pipe(var->pipe_fd) == -1)
		exit(EXIT_FAILURE);
	var->fd = open(argv[1], O_RDONLY);
	if (var->fd2 == -1)
		exit(EXIT_FAILURE);
	if (var->fd == -1)
		exit(EXIT_FAILURE);
	dup2(var->fd, STDIN_FILENO);
	dup2(var->pipe_fd[1], STDOUT_FILENO);
	// PREMIER FORK
	var->pid[0] = fork();
	if (var->pid[0] == - 1)
		exit(EXIT_FAILURE);
	if (!var->pid[0])
		_child_process(var, argv, env);
	var->fd2 = open(argv[4], O_RDONLY | O_TRUNC | O_CREAT, 0644);
	if (var->fd2 == -1)
		exit(EXIT_FAILURE);
	/*printf("coucou");*/
	dup2(var->pipe_fd[0], STDIN_FILENO);
	dup2(var->fd2, STDOUT_FILENO);
	//DEUXIEME FORK
	var->pid[1] = fork();
	if (var->pid[1] == - 1)
		exit(EXIT_FAILURE);
	if (!var->pid[1])
		_second_child_process(var, argv, env);
	close(var->pipe_fd[1]);
	close(var->pipe_fd[0]);
	waitpid(var->pid[0], NULL, 0);
	waitpid(var->pid[1], NULL, 0);
}

int	main(int arc, char **argv, char **env)
{
	if (arc != 5)
		return (EXIT_FAILURE);
	t_struct	*var;

/*	var = (t_struct){};*/
	var = ft_calloc(1, sizeof(var));
	_init_things(var, argv, env);
	return (0);
}