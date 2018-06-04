#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int fd;
char *word;
size_t wordLen;

int compareToWord()
{
  char c;
  for (size_t i = 0; i < wordLen; i++)
  {
    read(fd, &c, sizeof(c));

    if (c != word[i] || c == '\n')
    {
      if (c < word[i])
      {
        return 1;
      }

      return -1;
    }
  }

  read(fd, &c, sizeof(c));
  if (c == '\n')
  {
    return 0;
  }

  return -1;
}

void printResult()
{
  char c;

  while (read(fd, &c, sizeof(c)))
  {
    if (c == '\0')
    {
      break;
    }

    write(1, &c, sizeof(c));
  }
}

void search(int start, int end)
{
  int middle = (start + end) / 2;
  if (middle == start || middle == end)
  {
    write(2, "Word not found\n", 16);
    exit(1);
  }

  lseek(fd, middle, SEEK_SET);

  char c;
  while (read(fd, &c, sizeof(c)))
  {
    if (c == '\0')
    {
      break;
    }
  }

  int result = compareToWord();

  if (result == 0)
  {
    printResult();
  }
  else if (result < 0)
  {
    search(start, middle);
  }
  else
  {
    search(middle, end);
  }
}

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    write(2, "Invalid parameters\n", 20);
    exit(1);
  }

  char *dictionary = argv[1];
  word = argv[2];
  if ((fd = open(dictionary, O_RDONLY)) == -1)
  {
    write(2, "Invalid file\n", 14);
    exit(1);
  }

  int end;

  end = lseek(fd, 0, SEEK_END);

  lseek(fd, 0, SEEK_SET);

  wordLen = strlen(word);

  search(0, end);
  exit(0);
}