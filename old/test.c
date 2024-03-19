#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	_child_process(int pdf[2])
{
	close(pdf[1]);
	dup2(pdf[0], 0);
	close(pdf[0]);
	execlp("wc", "wc", (char *)0);
}

void	_parent_process(int pdf[2])
{
	close(pdf[0]);
	dup2(pdf[1], 1);
	close(pdf[1]);
	execlp("ls", "ls", (char *)0);
}

int	main()
{
	pid_t	pid;
	int		pdf[2];

	if (pipe(pdf) == -1)
		return (1);
	if ((pid = fork()) == -1)
		return (1);
	if (pid == 0)
		_child_process(pdf);
	if (pid > 0)
		_parent_process(pdf);
}