// Напишете програма, която приема точно 2 аргумента. Първият може да бъде само --min, --max или --print (вижте man 3 strcmp). Вторият аргумент е двоичен файл, в който има записани цели неотрицателни двубайтови числа (uint16_t - вижте man stdint.h). Ако първият аргумент е:

// --min - програмата отпечатва кое е най-малкото число в двоичния файл.
// --max - програмата отпечатва кое е най-голямото число в двоичния файл.
// --print - програмата отпечатва на нов ред всяко число.
// Използвайте двоичния файл binary/dump или генерирайте сами такъв (правилно подравнен).

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		exit(-1);
	}

	bool is_min = false;
	bool is_max = false;
	bool is_print = false;

	if ((is_min = (strcmp(argv[1], "--min") != 0)) && (is_max = (strcmp(argv[1], "--max") != 0)) && (is_print = (strcmp(argv[1], "--print") != 0)))
	{
		exit(-1);
	}

	int readFile;
	uint16_t number;

	// uint16_t min;
	// uint16_t max;
	// write(1, (const void *)&min, 1);
	// write(1, (const void *)&max, 1);

	if ((readFile = open(argv[2], O_RDONLY)) == -1)
	{
		exit(-1);
	}

	while (read(readFile, &number, sizeof(number)))
	{
		if (is_print)
		{
			write(1, "1", 1);
		}
	}

	exit(0);
}
