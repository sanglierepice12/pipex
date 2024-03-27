/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:08:54 by gsuter            #+#    #+#             */
/*   Updated: 2024/03/22 12:08:54 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	_init_path(t_struct *var, char **env)
{
	size_t		i;
	char	*temp;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
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

char	**_init_cmd(char **cmd, t_struct *var)
{
	size_t	i;

	if (!cmd)
		return (NULL);
	printf("bite\n");
	i = 0;
	while (var->path[i])
	{
		var->exec = ft_strjoin(var->path[i], cmd[0]);
		if (!access(var->exec, F_OK) && !access(var->exec, X_OK))
		{
			free(cmd[0]);
			cmd[0] = ft_strdup(var->exec);
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
	free(var);
}
