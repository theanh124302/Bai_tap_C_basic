#include<stdio.h>
void CharReadWrite(FILE *fin, FILE *fout)
{
int c;
while ((c=fgetc(fin)) != EOF){
if islower(c) c=toupper(c);
if isupper(c) c=tolower(c);
fputc(c, fout); /* write to a file */
putchar(c);
/* display character on the screen */
}
}
