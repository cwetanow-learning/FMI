// Реализирайте команда wc, с един аргумент подаден като входен параметър
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(2, "err\n", 4);
	}
	int readFile;
	char c;

	int writes[argc - 2];

	if ((readFile = open(argv[1], O_RDONLY)) == -1)
	{
		exit(-1);
	}

	for (int i = 0; i < argc - 2; i++)
	{
		if ((writes[i] = open(argv[i + 2], O_CREAT | O_WRONLY)) == -1)
		{
			write(1, "Cant open file ", 4);
			continue;
		}
	}

	while (read(readFile, &c, 1))
	{
		for (int i = 0; i < argc - 2; i++)
		{
			write(writes[i], &c, 1);
			continue;
		}
	}

	close(readFile);

	exit(0);
}
