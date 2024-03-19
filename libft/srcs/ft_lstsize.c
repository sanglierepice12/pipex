/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gostr@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:50:06 by gsuter            #+#    #+#             */
/*   Updated: 2024/02/26 16:50:06 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	temp;

	if (!lst)
		return (0);
	i = 1;
	temp = *lst;
	while (temp.next)
	{
		temp = *temp.next;
		i++;
	}
	return (i);
}
