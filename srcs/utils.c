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
				return (1);//equal
		}
		if (string[i])
			i++;
	}
	return (0);//not equal
}

/*
int main(int arc, char **arv, char **env)
{
	if (arc == 1)
		arv[1] = "PATH";
	int i = 0;
	while (_comp(env[i], arv[1]) != 1)
		i++;
	printf("%s\n pos[%d]", (env[i] + 5), i);
	return (0);
}
*/
