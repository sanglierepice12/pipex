/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:50:41 by gostr             #+#    #+#             */
/*   Updated: 2024/03/15 11:50:41 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	_child_process(t_struct **var)
{
	/*//cmd1 vérif
	(*var)->fd_in;
	(*var)->cmd1;
	//fork
	// child -> execv(cmd1, arg fd_in)
	//parent -> wait
	//vérif cmd2 linked cmd 1
	(*var)->cmd2;
	//execv (cmd2, fd[1] parent fd_out)*/
}

void	_second_child(t_struct **var)
{
	/*(*var)->fd_out
	waitpid((*var)->pid_one,(*var)->status)*/
}
