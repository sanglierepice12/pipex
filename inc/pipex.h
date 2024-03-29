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
typedef struct s_struct
{
	pid_t	pid;
	pid_t	pid2;
	int		pipe_fd[2];
	char	**path;
	int		fd;
	int		fd2;
	char	**cmd1;
	char	**cmd2;
	char	*exec;
	char	*exec2;
}				t_struct;

/* ------- PROCESS -------*/
void	_child_process(t_struct *var, char **argv);
void	_second_child_process(t_struct *var, char **argv);

/* ------- INIT -------*/
void	_init_path(t_struct *var, char **env);
void	_check_cmd(t_struct *var, char **argv, int flag);
char	**_init_cmd(char **cmd, t_struct *var);
void	_free_things(t_struct *var);
void	ft_fail(t_struct *var);

#endif