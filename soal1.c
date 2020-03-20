#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>

void run(char *str)
{ 
   char *script[] = {"bash", str, NULL};
   execv("/bin/bash", script);
}

int batas(char arr[])
{
  int i;
  for (i = 0; i < strlen(arr); i++)
  {
    if (arr[i] < '0' || arr[i] > '9')
    {
      return 0;
    }
  }
  return 1;
}

int cek(char arr[])
{
  if((strcmp(arr, "*")) == 0)
  {
    return 1; 
  }
  return 0;
}

int main(int argc, char *argv[])
{

  int status;
  int i,a,b,c;
 

  if(argc < 5 || argc > 5)
  {
    printf("Argumen wajib 4!!!\n");
    exit(EXIT_FAILURE);
  }

  else if(argc == 5)
  {
    int arr[4];

    for (i = 1; i < 4; i++)
    {
      if (batas(argv[i]))
      {
        arr[i] = atoi(argv[i]);
      }
      else if (cek(argv[i]))
      {
        arr[i] = -1;
      }
      else 
      {
        printf("Argumen %d salah!!!\n", i);
        exit(EXIT_FAILURE);
      }
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]);

    if (a < 0 || a > 59)
    {
      printf("Range detik salah!!!\n detik harus 0 - 59. \n");
      exit(EXIT_FAILURE);
    }
    else if (b < 0 || b > 59)
    {
      printf("Range menit salah!!!\n menit harus 0 - 59. \n");
      exit(EXIT_FAILURE);
    }
    else if (c < 0 || c > 23)
    {
      printf("Range jam salah!!!\n jam harus 0 - 23. \n");
      exit(EXIT_FAILURE);
    }    

    char path[100];
    strncpy(path, argv[4], 99);
    path[100] = '\0';

  pid_t pid, sid, child;
        
    pid = fork();

    if (pid < 0)
    {
      exit(EXIT_FAILURE);
    }

    if (pid > 0)
    {
      exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();

    if (sid < 0)
    {
      exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    

    while (1) 
    {
      time_t now = time(NULL);
      struct tm* timeNow = localtime(&now);

      a = timeNow->tm_sec;
      b = timeNow->tm_min;
      c = timeNow->tm_hour;

      if ((a == arr[1] || arr[1] == -1) && (b == arr[2] || arr[2] == -1) && (c == arr[3] || arr[3] == -1))
      {
	child = fork();
        if (child == 0)
        {    
          run(path);
        }
        else 
	while ((wait(&status)) > 0);
      }
      sleep(1);
    }
  }
  return 0;
}
