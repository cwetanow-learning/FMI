/*
Да се напише програма на С, която получава като параметър команда (без параметри) и при успешното ѝ изпълнение, извежда на стандартния изход името на командата.
*/

#include <unistd.h>
#include <stdlib.h>
#include <err.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		exit(-1);
	}

	if (execl(argv[1], argv[1], (char *)NULL) != -1)
	{
		write(1, argv[1], 4);
	}

	exit(0);
}
