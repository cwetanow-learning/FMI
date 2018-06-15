#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

#include <ctype.h>

#define READ 0
#define WRITE 1

char *skipSpace(char *str)
{
  while (*str == ' ')
  {
    ++str;
  }

  return str;
}

char *goToNextSpace(char *str)
{
  while (*str != ' ')
  {
    ++str;
  }

  return str;
}

void executeSimpleCommand(char **args)
{
  printf("%s\n", args[0]);
  execvp(args[0], args);
}

void execute(char *line)
{

  system(line);
  // char *args[512];
  // int index = 1;
  // char *next = goToNextSpace(line);

  // while (next != NULL)
  // {
  //   line = skipSpace(line);
  //   next[0] = '\0';
  //   args[index] = line;
  //   line = skipSpace(next + 1);

  //   ++index;
  // }

  // if (line[0] != '\0')
  // {
  //   args[index] = line;
  //   ++index;
  // }

  // args[index] = NULL;
  // printf("%s 12 \n", args[0]);
  // printf("12");

  // executeSimpleCommand(args);
}

char *getInput()
{
  char c;
  char input[1024];
  int i = 0;

  char *result = input;

  while (read(READ, &c, sizeof(c)))
  {
    if (c == '\n')
    {
      input[i - 1] = '\0';
      return result;
    }

    input[i] = c;
    i++;
  }

  input[i] = '\0';

  return result;
}

// int main(int argc, char **argv)
int main()
{
  // if (argc < 2)
  // {
  //   write(2, "Invalid parameters\n", 20);
  //   exit(1);
  // }

  int tasks = 4;
  int maxParallel = 2;

  int currentExecutingTasks = 0;
  int current = 0;
  int status = 0;

  int pid2[tasks];

  while (current < tasks)
  {
    if (currentExecutingTasks < maxParallel)
    {
      pid2[current] = fork();

      if (pid2[current] == 0)
      {
        char *input = getInput();
        execute(input);

        currentExecutingTasks--;
        exit(0);
      }
      else
      {
        currentExecutingTasks++;
        current++;
      }
    }
    else
    {
      wait(NULL);
      currentExecutingTasks--;
    }
  }

  while ((wait(&status)) > 0)
  {
  };

  return 0;
}