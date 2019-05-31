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

  // Open directory
  struct dirent *d;
  DIR *dircty = opendir(".");
  if (dircty == NULL)
  {
    printf("Cannot open that directory");
    exit(0);
  }

  // Repeatly read and print entries
  while ((d = readdir(dircty)) != NULL)
  {
    struct stat buf;
    stat(d->d_name, &buf);
    printf("%lld %s\n", buf.st_size, d->d_name);
  }

  // Close directory
  closedir(dircty);
  return 0;
}