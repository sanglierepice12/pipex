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
	size_t	i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	var->path = ft_split(env[i] + 5, ':');
	i = 0;
	while (var->path[i])
	{
		var->path[i] = ft_strjoin(var->path[i], "/");
		i++;
	}
}

void	_free_things(t_struct *var)
{
	if (var->path)
		ft_free_tab(var->path);
	if (var->cmd1)
		ft_free_tab(var->cmd1);
	if (var->cmd2)
		ft_free_tab(var->cmd2);
	if (var->exec)
		free(var->exec);
	if (var->exec)
		free(var->exec);
	free(var);
}