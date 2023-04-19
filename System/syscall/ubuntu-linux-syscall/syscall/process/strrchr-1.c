#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "This is a sample string";
  char * pch;
  pch=strrchr(str,'s');
  printf ("Last occurence of 's' found at %ld \n",pch-str+1);
  printf("%s \n", pch);
  return 0;
}
