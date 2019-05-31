#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  // Parse command line
  char *path;
  if (argc>1)  //Make sure there is more than just the main argument.
  {
    path = argv[1];  // Get the first input argument after the main arg.  Ignore any extra args.
  } else {
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

  // Repeatedly read and print entries
  while ((d = readdir(dircty)) != NULL)
  {
    struct stat buf;
    stat(d->d_name, &buf);
    printf("%ld %s\n", buf.st_size, d->d_name);
  }

  // Close directory
  closedir(dircty);
  return 0;
}