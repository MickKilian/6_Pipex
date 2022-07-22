#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	 main(int argc, char *argv[])
{
	int	arr[] = {2, 1, 4, 5, 2, 1, 4};
	int	id;
	int	n;
	int	i = 0;
	int	tot = 0;
	int other = 0;
	int	fd[2];

	if (pipe(fd) == -1)
	{
		printf("An error occurred when opening the pipe\n");
		return (1);
	}
	id = fork();
	if (!id)
	{
		i = 0;
		n = 3;
	}
	else
	{
		i = 3;
		n = 7;
	}
	while (i++ < n)
		tot += arr[i - 1];
	if (!id)
	{
		close(fd[0]);
		write(fd[1], &tot, sizeof(int));
		close(fd[1]);
		printf("total for child process is  %d\n", tot);
	}
	else
	{
		close(fd[1]);
		read(fd[0], &other, sizeof(int));
		close(fd[0]);
		printf("total for main process is  %d\n", tot);
		tot += other;
		if (wait(NULL) == -1)
		{
			printf("Error when using wait function.\n");
			return (2);
		}
		printf("overall total is : %d\n", tot);
	}
	return (0);
}
