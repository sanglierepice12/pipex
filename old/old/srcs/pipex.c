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

int	main(int arc, char **argv, char **env)
{
	pid_t	pid;
	int		end[2];
	int		i;
	char	**dest;
	//char	**stong;

	if (arc < 2)
		return (EXIT_FAILURE);
	i = -1;
	while (++i, env[i])
	{
		if (_comp(env[i], argv[1]))
		{
			dest = ft_split(env[i], '=');
			//ft_printf("%s\n", dest[1]);
			//stong = {dest[1], ".", NULL};
			char *args[] = {"ls -l",NULL};
			execv(dest[1], args);
			//execv(dest[1], stong);
		}
	}
	if (pipe(end) == -1)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0)
		_child_process(pid, end);
	else
		_parent_process(pid, end);
	return (0);
}