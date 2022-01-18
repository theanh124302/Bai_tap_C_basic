#include<stdio.h>
#include<string.h>
void tlps(char* pat, int M, int* lps) {
   int length = 0;
   lps[0] = 0;
   int i = 1;
   while (i < M) {
      if (pat[i] == pat[length]) {
         length++;
         lps[i] = length;
         i++;
      } else {
         if (length != 0)
         length = lps[length - 1];
         else {
            lps[i] = 0;
            i++;
         }
      }
   }
}
void KMPA(char* text, char* pattern) {
   int M = strlen(pattern);
   int N = strlen(text);
   int lps[M];
   tlps(pattern, M, lps);
   int i = 0;
   int j = 0;
   while (i < N) {
      if (pattern[j] == text[i]) {
         j++;
         i++;
      }
      if (j == M) {
         printf("Vi tri %d\n", i - j);
         j = lps[j - 1];
      }
      else if (i < N && pattern[j] != text[i]) {
         if (j != 0)
         j = lps[j - 1];
         else
         i = i + 1;
      }
   }
}
int main() {
   char text[] = "xyztrwqxyzfg";
   char pattern[] = "xyz";
   printf("Ket qua tim kiem :\n");
   KMPA(text, pattern);
   return 0;
}
