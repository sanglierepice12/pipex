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
	int i;

	i = 0;
	if (!env)
		exit(EXIT_FAILURE);
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	var->path = ft_split(env[i] + 5, ':');
}