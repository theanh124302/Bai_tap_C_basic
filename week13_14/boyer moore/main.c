#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int BoyerMoore(char *source, char *find)
{
  int skip[MAX], i = 0, len, j=-1, lensource;

  len = strlen(find);
  lensource = strlen(source);
  for (i=0; i<MAX; i++)
    skip[i] = len-1;
  for (i=0; i<len; i++)
    if (skip[find[i]] == len-1)
       skip[find[i]] = len-i-1;

  i = j = len-1;
  do {
    if (source[i] == find[j])
    {
      i--;
      j--;
    }
    else
    {
      if (len-j+1 > skip[source[i]])
        i += len-j+1;
      else
        i += skip[source[i]];
      j = len-1;
    }
  } while (j>0 && i<lensource);

  if (j<=0)
    return i;
  else
    return -1;
}

int main()
{
    printf("%d",BoyerMoore("abcdef","cd"));
    return 0;
}
