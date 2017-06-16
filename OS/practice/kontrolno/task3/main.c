#include <stdio.h>
#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int f1;
	int f2;
	int f3;
	uint32_t num;
	uint32_t range;
	uint32_t start;

	if ((f1 = open("f1", O_RDONLY)) == -1)
	{
		write(2, "Err", 4);
	}

	if ((f2 = open("f2", O_RDONLY)) == -1)
	{
		write(2, "Err", 4);
	}

	if ((f3 = open("f3", O_CREAT | O_WRONLY)) == -1)
	{
		write(2, "Err", 4);
	}

	int first = 0;

	while (read(f1, &num, sizeof(num)))
	{
		if (first == 0)
		{
			start = num;
			first++;
		}
		else
		{
			range = num;
			first = 0;

			lseek(f2, start, SEEK_SET);
			for (uint32_t i = 0; i < range; i++)
			{
				read(f2, &num, sizeof(num));
				write(f3, &num, sizeof(num));
			}
		}
	}

	exit(0);
}
