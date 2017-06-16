/*
Koпирайте файл /etc/passwd в текущата ви работна директория и променете разделителят на копирания файл от ":", на "?"
*/

#include <stdio.h>
#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int passwd;
	int fd;
	char c;

	if ((passwd = open("passwd", O_RDONLY)) == -1)
	{
		write(2, "Err", 4);
	}

	if ((fd = open("res", O_CREAT | O_WRONLY)) == -1)
	{
		write(2, "Err", 4);
	}

	while (read(passwd, &c, 1))
	{
		if (c == ':')
		{
			c = '?';
		}

		write(fd, &c, 1);
	}

	close(passwd);
	close(fd);

	exit(0);
}
