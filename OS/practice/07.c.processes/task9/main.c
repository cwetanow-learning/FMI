/*
Да се напише програма на C, която която създава файл в текущата директория и генерира два процесa, които записват низовете foo и bar в създадения файл.
Програмата не гарантира последователното записване на низове.
Променете програмата така, че да записва низовете последователно, като първия е foo.
*/

#include <stdio.h>
#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int fd;
	if ((fd = open("test.txt", O_CREAT | O_WRONLY)) == -1)
	{
		write(2, "Err", 4);
	}

	int status;

	if (fork() > 0)
	{
		wait(&status);

		fd = open(argv[1], O_RDONLY);

		char c;
		int i = 0;

		while (read(fd, &c, 1))
		{
			if (i == 2)
			{
				write(1, " ", 1);
				i = 0;
			}

			i++;
			write(1, &c, 1);
		}
	}
	else
	{
		write(fd, "foobar", sizeof("foobar"));
		close(fd);
	}

	exit(0);
}
