/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:26:28 by gsuter            #+#    #+#             */
/*   Updated: 2024/03/22 11:26:28 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	_init_things(t_struct *var, char **argv, char **env)
{
	if (pipe(var->pipe_fd) == -1)
		return (exit(EXIT_FAILURE));

	// PREMIER FORK
	var->pid = fork();
	if (var->pid == - 1)
		return (exit(EXIT_FAILURE));
	if (!var->pid)
		_child_process(var, argv, env);

	/*//DEUXIEME FORK
	var->pid_child = fork();
	if (var->pid_child == - 1)
		return (exit(EXIT_FAILURE));
	if (!var->pid_child)
		_second_child_process(var, argv);*/
	waitpid(var->pid, NULL, 0);
	//waitpid(var->pid_child, NULL);
	close(var->pipe_fd[1]);
	free(var);
}

int	main(int arc, char **argv, char **env)
{
	if (arc != 5)
		return (EXIT_FAILURE);
	t_struct	*var;

	var = calloc(1, sizeof(t_struct));
	_init_things(var, argv, env);
	return (0);
}