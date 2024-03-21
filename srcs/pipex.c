/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:44:46 by gostr             #+#    #+#             */
/*   Updated: 2024/03/15 11:44:46 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	_process(t_struct **var)
{
	if ((*var)->pid_one == 0)
		_child_process(var);
	if ((*var)->pid_two == 0)
		_second_child_process()
	if ((*var)->pid_one > 0)
		_parent_process(var);
}


int	main(int arc, char **argv, char **env)
{
	t_struct	*var;

	if (arc != 5)
		return (argv[1] = NULL, EXIT_FAILURE);
	var = calloc(1, sizeof(t_struct));
	_init(&var, env, argv);
	_process(&var);
	return (0);
}