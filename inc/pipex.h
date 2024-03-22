/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:45:05 by gostr             #+#    #+#             */
/*   Updated: 2024/03/18 12:30:24 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/incs/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

/* ------- PRINTF -------*/
# include <stdio.h>
/* ------- ------ -------*/

/* ------- STRUCT -------*/
typedef struct	s_struct
{
	pid_t	pid;
	pid_t	pid_child;
	int		pipe_fd[2];
	char	**path;
	int		fd;
	char	*cmd1;
	char	*cmd2;
	char	**exec;
}				t_struct;

/* ------- PIPEX -------*/


/* ------- PROCESS -------*/
void	_child_process(t_struct *var, char **argv, char **env);
/*void	_second_child_process(t_struct *var, char **argv);*/

/* ------- UTILS -------*/
int		_comp(char *path, char *look_for);

/* ------- INIT -------*/
void	_init_path(t_struct *var, char **env);

#endif