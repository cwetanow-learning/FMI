#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(2, "err\n", 4);
	}

	int fd;
	char c;

	for (int i = 1; i < argc; i++)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
		{
			write(1, "Cant open file ", 4);
			continue;
		}

		while (read(fd, &c, 1))
		{
			write(1, &c, 1);
		}

		close(fd);
	}

	exit(0);
}
