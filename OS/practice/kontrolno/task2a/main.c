/*
Да се напише програма на С, която получава като параметър име на файл. Създава процес син, който записва стринга foobar във файла (ако не съществува, го създава, в противен случай го занулява), след което процеса родител прочита записаното във файла съдържание и го извежда на стандартния изход, добавяйки по един интервал между всеки два символа.
*/

#include <stdio.h>
#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(2, "err", 1);
		exit(-1);
	}

	int pipefd[2];

	if (pipe(pipefd) == -1)
	{
		errx(1, "Couldnt pipe");
	}

	pid_t childPid = fork();

	if (childPid > 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		if (execlp("sort", "sort", argv[1], NULL) == -1)
		{
			errx(1, " ");
		}
		close(pipefd[0]);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		if (execlp("cat", "cat", argv[1], NULL) == -1)
		{
			errx(1, " ");
		}
		close(pipefd[1]);
	}

	exit(0);
}
