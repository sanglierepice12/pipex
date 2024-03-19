/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:28:17 by gostr             #+#    #+#             */
/*   Updated: 2024/03/19 09:28:17 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	_init_fd(char *file, char *second_file, t_struct **var)
{
	if (((*var)->fd_in = open(file, O_RDONLY) == -1))
		exit(EXIT_FAILURE);
	if (((*var)->fd_out = open(second_file, O_WRONLY | O_CREAT, 0666)) == -1)
		exit(EXIT_FAILURE);
}

void	_init_pid_pipe(t_struct **var)
{
	if (((*var)->pid_one = fork()) == -1)
		exit(EXIT_FAILURE);
	if (pipe((*var).fds) == -1)
		exit(EXIT_FAILURE);
}

void	_init_path(t_struct **var, char **env)
{
	int	i;

	i = 0;
	while (_comp(env[i], "PATH") != 1)
		i++;
	(*var)->path1 = (env[i] + 5);
}

void	_init(t_struct **var, char **env)
{
	_init_fd(argv[1], argv[4], var);
	_init_pid(var);
	_init_path(var, env);
}