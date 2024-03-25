/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:04:49 by gsuter            #+#    #+#             */
/*   Updated: 2024/03/22 12:04:49 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	_find_cmd(t_struct *var, char **argv)
{
	int		i;

	i = -1;
	while (++i, var->path[i])
		var->path[i] = ft_strjoin(var->path[i], "/");
	i = 0;
	var->path2 = ft_split(argv[2], 32);
	while (var->path[i])
	{
		var->cmd1 = ft_strjoin(var->path[i], var->path2[0]);
		if (!access(var->cmd1, X_OK))
		{
			free(var->path2[0]);
			free(var->path2[1]);
			break;
		}
		free(var->cmd1);
		i++;
	}
	printf("pas trouvé");
	if (!var->path[i])
		exit(EXIT_FAILURE);
}

void	_child_process(t_struct *var, char **argv, char **env)
{
	if (!access(argv[2], X_OK))
		var->cmd1 = argv[2];
	else
		_init_path(var, env);
	if (!var->cmd1)
		_find_cmd(var, argv);
	close(var->pipe_fd[0]);
	close(var->fd);
	var->exec = ft_calloc(2, sizeof(char *));
	var->exec[0] = argv[2];
	var->exec[1] = NULL;
	execve(var->cmd1, var->exec, env);
	ft_printf("Error");
	exit(EXIT_FAILURE);
}

void	_second_child_process(t_struct *var, char **argv, char **env)
{
	if (!access(argv[3], X_OK))
		var->cmd1 = argv[3];
	else
		_init_path(var, env);
	if (!var->cmd1)
		_find_cmd(var, argv);
	close(var->pipe_fd[0]);
	close(var->fd2);
	var->exec = ft_calloc(2, sizeof(char *));
	var->exec[0] = argv[3];
	var->exec[1] = NULL;
	execve(var->cmd1, var->exec, env);
	ft_printf("Error");
	exit(EXIT_FAILURE);
}
