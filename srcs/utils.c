/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:11:16 by gostr             #+#    #+#             */
/*   Updated: 2024/03/15 15:11:16 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <stdio.h>
int	_comp(char *string, char *look_for)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (string[i])
	{
		j = 0;
		while (string[i] && string[i] == look_for[j])
		{
			i++;
			j++;
			if (!look_for[j])
				return (printf("egal\n"), 1);
		}
		if (string[i])
			i++;
	}
	return (printf("pas egal\n"), 0);
}

/*
int main(int arc, char **arv, char **env)
{
	if (!arc)
		return 0;
	int i = 0;
	while (_comp(env[i], arv[1]) != 1)
		i++;
	printf("%s\n pos[%d]", (env[i] + 5), i);
	return (0);
}*/
