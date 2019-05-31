#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  // Parse command line
  char *path;
  if (argc > 1) //Make sure there is more than just the main argument.
  {
    path = argv[1]; // Get the first input argument after the main arg.  Ignore any extra args.
  }
  else
  {
    path = ".";
  }

  printf("Input path is: %s\n", path);

  // Open directory
  struct dirent *d;
  DIR *dircty = opendir(path);
  if (dircty == NULL)
  {
    printf("Cannot open that directory.\n");
    exit(0);
  }

  char *full_path;
  // Repeatedly read and print entries
  while ((d = readdir(dircty)) != NULL)
  {
    struct stat buf;
    full_path[0] = '\0'; //Make sure it is clear for each loop.
    strcat(full_path, path);
    strcat(full_path, "/");
    strcat(full_path, d->d_name);
    if (stat(full_path, &buf) == -1)
    {
      printf("%10s %s\n", "?", d->d_name);
    }
    else if (S_ISDIR(buf.st_mode) != 0)
    {
      printf("%10s %s\n", "<DIR>", d->d_name);
    }
    else
    {
      printf("%10ld %s\n", buf.st_size, d->d_name);
    }
  }

  // Close directory
  closedir(dircty);
  return 0;
}