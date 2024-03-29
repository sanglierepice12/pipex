/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:08:54 by gsuter            #+#    #+#             */
/*   Updated: 2024/03/29 14:17:51 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	_init_path(t_struct *var, char **env)
{
	size_t		i;
	char		*temp;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
	{
		var->path = NULL;
		return ;
	}
	var->path = ft_split(env[i] + 5, ':');
	i = 0;
	while (var->path[i])
	{
		temp = var->path[i];
		var->path[i] = ft_strjoin(temp, "/");
		i++;
		free(temp);
	}
}

void	_check_cmd(t_struct *var, char **argv, int flag)
{
	if (flag)
	{
		if (argv[2][0] == '\0')
			argv[2] = NULL;
		var->cmd1 = ft_split(argv[2], 32);
		if (!var->cmd1)
			ft_fail(var);
		if (access(argv[2], F_OK) && access(argv[2], X_OK))
			var->cmd1 = _init_cmd(var->cmd1, var);
	}
	if (!flag)
	{
		if (argv[3][0] == '\0')
			argv[3] = NULL;
		var->cmd2 = ft_split(argv[3], 32);
		if (!var->cmd2)
			ft_fail(var);
		if (access(argv[3], F_OK) && access(argv[3], X_OK))
			var->cmd2 = _init_cmd(var->cmd2, var);
	}
}

char	**_init_cmd(char **cmd, t_struct *var)
{
	size_t	i;

	i = 0;
	if (!cmd || !var->path)
	{
		if (cmd)
			ft_free_tab(cmd);
		return (NULL);
	}
	while (var->path[i])
	{
		var->exec = ft_strjoin(var->path[i], cmd[0]);
		if (!access(var->exec, F_OK | X_OK))
		{
			free(cmd[0]);
			cmd[0] = ft_strdup(var->exec);
			return (free(var->exec), cmd);
		}
		i++;
		free(var->exec);
	}
	return (cmd);
}

void	_free_things(t_struct *var)
{
	if (var->path)
		ft_free_tab(var->path);
	if (var->cmd1)
		ft_free_tab(var->cmd1);
	if (var->cmd2)
		ft_free_tab(var->cmd2);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	free(var);
}
