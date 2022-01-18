#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char hoten[30],email[20],sdt[20],ho[30],dem[30],ten[30];
} ds;
ds fi[30];
char x;
void tach(ds *f)
{
    int i=0,j=strlen(f->hoten);
    while((f->hoten[i]!=' ')&&(f->hoten[i]!='\n')){
        i++;
    }
    while(f->hoten[j]!=' '){
        j--;
    }
    for(int x=0;x<i;x++){
        f->ho[x]=f->hoten[x];
    }
    for(int x=(j+1);x<strlen(f->hoten);x++){
        f->ten[x-j-1]=f->hoten[x];
    }
    for(int x=i+1;x<j;x++){
        f->dem[x-i-1]=f->ten[x];
    }
}
int partition (ds f[], int low, int high)
{
    char pivot[30];
    strcpy(pivot,f[high].ten);
    int left = low;
    int right = high - 1;
    ds doi1,doi2;
    while(1){
        while(left <= right && strcmp(f[left].ten,pivot)<0) left++;
        while(right >= left && strcmp(f[right].ten,pivot)>0) right--;
        if (left >= right) break;
        doi1=f[left];
        f[left]=f[right];
        f[right]=doi1;
        left++;
        right--;
    }
    doi2=f[left];
    f[left]=f[high];
    f[high]=doi2;
    return left;
}
void quickSort(ds f[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(f, low, high);
        quickSort(f, low, pi - 1);
        quickSort(f, pi + 1, high);
    }
}
int main(){
    int dem2=0,dem3=0;
    FILE *f=fopen("ds.txt","r+");
    FILE *dr=fopen("daura.txt","w+");
    while(fscanf(f,"%c",&x)!=EOF){
        if(x=='\n'){
            dem3=0;
            dem2++;
        }
        if(dem2%3==0){
            fi[dem2/3].hoten[dem3]=x;
        }
        else if(dem2%3==1){
            fi[dem2/3].sdt[dem3]=x;
        }
        else if(dem2%3==2){
            fi[dem2/3].email[dem3]=x;
        }
        dem3++;
        if(x=='\n'){
            dem3--;
        }
    }
    int size=(dem2)/3;
    for(int i=0;i<size;i++){
        tach(&fi[i]);
    }
    quickSort(fi,0,size-1);
    for(int i=0;i<size;i++){
        fprintf(dr,"%d. ho va ten: %s\n",i+1,fi[i].hoten);
        fprintf(dr,"sdt : %s\n",fi[i].sdt);
        fprintf(dr,"gmail: %s\n\n",fi[i].email);
    }
    fclose(f);
    fclose(dr);
}
