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
		exit(-1);
	}

	int fd;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(2, "Err", 4);
	}

	int chars[256];

	char c;
	while (read(fd, &c, 1))
	{
		chars[(int)c]++;
	}

	close(fd);
	write(1, "Done", 4);

	if ((fd = open(argv[1], O_WRONLY)) == -1)
	{
		write(2, "Err", 4);
	}

	for (int i = 0; i < 256; i++)
	{
		c = (char)i;

		for (int j = 0; i < chars[i]; j++)
		{
			write(fd, &c, 1);
		}
	}

	close(fd);

	exit(0);
}
