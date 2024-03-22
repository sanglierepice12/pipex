/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:10:38 by gsuter            #+#    #+#             */
/*   Updated: 2024/03/22 12:10:38 by gsuter           ###   ########.fr       */
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
