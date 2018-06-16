#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define READ 0
#define WRITE 1

void execute(char *line)
{
  system(line);

  // Should be with exec(), pipe() and dup2()...
}

int isDone = 0;

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
  isDone = 1;

  return result;
}

int getMaxParallel(char *input)
{
  int result = 0;

  int length = strlen(input);
  int counter = 1;

  for (int i = length - 1; i > -1; i--)
  {
    result += ((int)input[i] - 48) * counter;
    counter *= 10;
  }

  return result;
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    write(2, "Invalid parameters\n", 20);
    exit(1);
  }

  int maxParallel = getMaxParallel(argv[1]);

  int currentExecutingTasks = 0;
  int status = 0;

  while (!isDone)
  {
    if (currentExecutingTasks < maxParallel)
    {
      char *input = getInput();

      int pid = fork();

      if (pid == 0)
      {
        execute(input);

        exit(0);
      }
      else
      {
        currentExecutingTasks++;
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