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

/* ------- STRUCT -------*/
typedef struct s_struct
{
	char	**path1;
	int		fd_in;
	int		fd_out;
	int		fds[2];
	int		status;
	pid_t	pid_one;
}t_struct;

/* ------- PIPEX -------*/
void	_process(t_struct **var);

/* ------- PROCESS -------*/
void	_child_process(t_struct **var);
void	_second_child_process(t_struct **var);

/* ------- UTILS -------*/
int		_comp(char *path, char *look_for);

/* ------- INIT -------*/
void	_init_fd(char *file, char *second_file, t_struct **var);
void	_init_pid(t_struct **var);
void	_init(t_struct **var, char **env, char **argv);

#endif