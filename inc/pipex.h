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

#define GREEN "\033[32m"
#define GREEN2 "\033[0m"

#define PRINTGREEN(text) printf(GREEN "%s" GREEN2, text)

/* ------- PRINTF -------*/
# include <stdio.h>
/* ------- ------ -------*/

/* ------- STRUCT -------*/
typedef struct	s_struct
{
	pid_t	pid;
	int		pipe_fd[2];
	char	**path;
	char	**arg_split;
	char	**arg_split2;
	int		fd;
	int		fd2;
	char	*cmd1;
	char	*cmd2;
	char	*exec[2];
	char	*exec2[2];
	int		count;
}				t_struct;

/* ------- PIPEX -------*/
void	_check_cmd(t_struct *var, char **argv);

/* ------- PROCESS -------*/
void	_child_process(t_struct *var, char **env);

/* ------- UTILS -------*/

/* ------- INIT -------*/
void	_init_path(t_struct *var, char **env);

#endif