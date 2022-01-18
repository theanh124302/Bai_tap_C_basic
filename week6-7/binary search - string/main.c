/*
Exercise•We assume that you make a mobile phone’s address book.
•Declare the structure which can store at least "name", "telephone number", "e-mail address.".
And declare an array of the structure that can handle about 100 address data.
•Read this array data of about 10 from an input file, and write a name which is equal to a specified name and whose array index is the smallest to an output file.
Use the binary search for this exercise
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[20],email[20],sdt[20];
} st;
st s[30],fi[30];
char x,y[1000];
int BinarySearch(st A[ ], char x[], int Low, int High ) {
    if (Low > High) return -1;
    int Mid = ( Low + High ) / 2;
    if (strcmp(A[Mid].name,x) < 0 )
        return BinarySearch(A, x, Mid+1, High);
    if (strcmp(A[Mid].name,x) > 0 )
        return BinarySearch(A, x, Low, Mid-1);
    if (strcmp(A[Mid].name,x) == 0 )
        return Mid;
    return -1;
}

int main(){

    int dem1=0,dem2=0,dem3=0;
    FILE *f=fopen("ds.txt","r+");
    FILE *dr=fopen("daura.txt","w+");
    while(fscanf(f,"%c",&x)!=EOF){
        y[dem1]=x;
        dem1++;
        if(x=='\n'){
            dem3=0;
            dem2++;
        }
        if(dem2%3==0){
            fi[dem2/3].name[dem3]=x;
        }
        if(dem2%3==1){
            fi[dem2/3].sdt[dem3]=x;
        }
        if(dem2%3==2){
            fi[dem2/3].email[dem3]=x;
        }
        dem3++;
        if(x=='\n'){
            dem3--;
        }
    }
    y[dem1]='\0';
    int size=(dem2)/3;
    for(int i=0;i<size;i++){
        fprintf(dr,"ten: %s\nsdt: %s\ngmail: %s\n",fi[i].name,fi[i].sdt,fi[i].email);
    }
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(strcmp(fi[i].name,fi[j].name)>0){
                st a=fi[i];
                fi[i]=fi[j];
                fi[j]=a;
            }
        }
    }
    fprintf(dr,"\n\nsau sap xep:\n");
    for(int i=0;i<size;i++){
        fprintf(dr,"\nten: %s\nsdt: %s\ngmail: %s\n",fi[i].name,fi[i].sdt,fi[i].email);
    }
    char timkiem[100];
    printf("nhap ten muon tim : ");
    fflush(stdin);
    gets(timkiem);
    int a = BinarySearch(fi,timkiem,0,size-1);
    fprintf(dr,"\n\nket qua tim kiem : \n");
    if(a!=-1){
        fprintf(dr,"Vi tri: %d\nten: %s\nsdt: %s\ngmail: %s\n",a+1,fi[a].name,fi[a].sdt,fi[a].email);
    }
    else{
        fprintf(dr,"\nkhong tim thay\n");
    };
    fclose(f);
    fclose(dr);
}
