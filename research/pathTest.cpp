#include <string>
#include <iostream>
#include <dirent.h>


int main()
{
  // "HDD1/Users/9625014/Programming I Folder/Term 3/Chess/saves";
  DIR *dir;
  struct dirent *ent;
  if((dir = opendir ("/Users/9625014/Programming1Folder/Term3/Chess")) != NULL)
  {
    while((ent = readdir(dir)) != NULL)
    {
      printf ("%s\n", ent->d_name);
    }
    closedir(dir);
  } else
  {
    perror("");
    return EXIT_FAILURE;
  }
}
