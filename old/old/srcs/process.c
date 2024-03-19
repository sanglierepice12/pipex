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
#include <stdio.h>

#ifndef EXIT_CODE
# define EXIT_CODE 42
#endif

static void	writestr(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void	_child_process(pid_t pid, int *end)
{
	char	buf;
	close(end[1]);
	ft_printf("i'm the child and my pid is :%d\n", pid);
	writestr(STDERR_FILENO, "coucou\n");
	while (read(end[0], &buf, 1) > 0)
		write(STDERR_FILENO, &buf, 1);
	close(end[0]);
	exit(EXIT_CODE);
}

void	_parent_process(pid_t pid, int *end)
{
	int	status;

	close(end[0]);
	ft_printf("i'm the parent and my child pid is %d\n", pid);
	sleep(1);
	writestr(end[1], "je suis le child et je reppond merci \n");
	close(end[1]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 42)
		{
			printf(
					"aller ca marche le code est bien : %d et tu ma donner %d\n",
					42, WEXITSTATUS(status));
		}
		else
			printf("bof bof tu m'as donné : %d au lieu de %d\n", WEXITSTATUS(status), 42);
	}
	exit(EXIT_SUCCESS);
}