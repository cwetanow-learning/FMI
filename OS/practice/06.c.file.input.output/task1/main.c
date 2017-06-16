// Реализирайте команда cp, работеща с два аргумента, подадени като входни параметри.

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int readFile;
	int writeFile;
	char c;

	if (argc != 3)
	{
		exit(-1);
	}

	if ((readFile = open(argv[1], O_RDONLY)) == -1)
	{
		exit(-1);
	}

	if ((writeFile = open(argv[2], O_CREAT | O_WRONLY)) == -1)
	{
		close(readFile);
		exit(-1);
	}

	while (read(readFile, &c, 1))
	{
		write(writeFile, &c, 1);
	}

	close(readFile);
	close(writeFile);

	exit(0);
}
