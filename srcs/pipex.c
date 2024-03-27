/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:09:51 by gostr             #+#    #+#             */
/*   Updated: 2024/03/25 17:12:32 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	_check_cmd(t_struct *var, char **argv)
{
	size_t	i;
	int		flag;
	int		flag2;

	flag = 1;
	flag2 = 1;
	if (!access(argv[2], F_OK) && !access(argv[2], X_OK))
		var->cmd1[0] = argv[2];
	else
		var->cmd1 = ft_split(argv[2], 32);
	if (!access(argv[3], F_OK) && !access(argv[3], X_OK))
		var->cmd2[0] = argv[3];
	else
		var->cmd2 = ft_split(argv[3], 32);
	i = 0;
	while (var->path[i])
	{
		if (flag == 1)
			var->exec = ft_strjoin(var->path[i], var->cmd1[0]);
		if (flag2 == 1)
			var->exec2 = ft_strjoin(var->path[i], var->cmd2[0]);
		if (!access(var->exec, F_OK) && !access(var->exec, X_OK))
		{
			var->cmd1[0] = ft_strdup(var->exec);
			flag = 0;
		}
		if (!access(var->exec2, F_OK) && !access(var->exec2, X_OK))
		{
			var->cmd2[0] = ft_strdup(var->exec2);
			flag2 = 0;
		}
		if (flag == 0 && flag2 == 0)
			break ;
		i++;
	}
}

void	_process(t_struct *var, char **argv, char **env)
{
	_check_cmd(var, argv);
	if (pipe(var->pipe_fd) == -1)
		exit(EXIT_FAILURE);
	var->fd = open(argv[1], O_RDONLY);
	if (var->fd == -1)
		exit(EXIT_FAILURE);
	if ((var->pid = fork()) == -1)
		exit(EXIT_FAILURE);
	if (var->pid == 0)
		_child_process(var, env);
	var->fd2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (var->fd2 == -1)
	{
		wait(NULL);
		perror("bite\n");
		exit(EXIT_FAILURE);
	}
	var->pid2 = fork();
	if (var->pid2 == -1)
		exit(EXIT_FAILURE);
	if (var->pid2 == 0)
		_second_child_process(var, env);
	close(var->pipe_fd[0]);
	close(var->pipe_fd[1]);
	waitpid(var->pid, 0, 0);
	waitpid(var->pid2, 0, 0);
}

int	main(int arc, char **argv, char **env)
{
	t_struct	*var;
	if (arc != 5)
		exit(EXIT_FAILURE);
	var = calloc(1, sizeof(t_struct));
	_init_path(var, env);
	_process(var, argv, env);
	_free_things(var);
	return (EXIT_SUCCESS);
}
