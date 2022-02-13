/*Nap vao 1 danh sach gom hoten, sdt, gmail bang file dau vao, dung cac thuat toan sap xep de sap xep lai danh sach theo thu tu tang dan cua ten.
Vi du ten day du la Hoang The Anh thi phan dung de sap xep la "Anh"
vi du: Nguyen A B, Nguyen B A sau khi sap xep se la :
Nguyen B A, Nguyen A B.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct link
{
    char hoten[30];
    char sdt[30];
    char gmail[30];
    struct link *next;
};
typedef struct link *node;
typedef struct
{
    char hoten[30],email[20],sdt[20],ho[30],dem[30],ten[30];
} ds;
ds fi[30];
char x,y[1000];
node them(node head, char a[], char b[], char c[]){
    node x,p;
    x = (node)malloc(sizeof(struct link));
    x->next = NULL;
    strcpy(x->hoten,a);
    strcpy(x->sdt,b);
    strcpy(x->gmail,c);
    if(head == NULL){
        head = x;
    }
    else{
        p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = x;
    }
    return head;
}
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
void insertionSort(ds arr[], int n)
{
   int i, j;
   ds key;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && (strcmp(arr[j].ten, key.ten)>0))
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
void selectionSort(ds arr[], int n)
{
    int i, j, min;
    ds temp;
    for (i = 0; i < n-1; i++)
    {
    min = i;
        for (j = i+1; j < n; j++){
            if (strcmp(arr[j].ten,arr[min].ten)<0){
                min = j;
            }
        }
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
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



void merge(ds f[], int left, int mid, int right)
{
    int i, j, k;
    int sizel = mid - left + 1;
    int sizer =  right - mid;
    ds L[sizel], R[sizer];
    for (i = 0; i < sizel; i++)
        L[i] = f[left + i];
    for (j = 0; j < sizer; j++)
        R[j] = f[mid + 1+ j];
    i = 0;
    j = 0;
    k = left;
    while (i < sizel && j < sizer)
    {
        if (strcmp(L[i].ten,R[j].ten)<=0)
        {
            f[k] = L[i];
            i++;
        }
        else
        {
            f[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < sizel)
    {
        f[k] = L[i];
        i++;
        k++;
    }
    while (j < sizer)
    {
        f[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(ds f[], int left, int right)
{
    if (left < right)
    {
        int mid = (left+right)/2;
        mergeSort(f, left, mid);
        mergeSort(f, mid+1, right);
        merge(f, left, mid, right);
    }
}

void heapify(ds f[], int n, int i)
{
    int x = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && strcmp(f[left].ten,f[x].ten)>0)
        x = left;
    if (right < n && strcmp(f[right].ten,f[x].ten)>0)
        x = right;
    if (x != i)
    {
        ds p = f[i];
        f[i] = f[x];
        f[x] = p;
        heapify(f, n, x);
    }
}
void heapSort(ds f[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(f, n, i);
    for (int i=n-1; i>0; i--)
    {
        ds p = f[0];
        f[0] = f[i];
        f[i] = p;
        heapify(f, i, 0);
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
    //insertionSort(fi,size-1);     //cac thuat toan sap xep
    //selectionSort(fi,size-1);
    quickSort(fi,0,size-1);
    //mergeSort(fi,0,size-1);
    //heapSort(fi,size);
    node head = NULL;
    for(int i=0;i<size;i++){
        head=them(head,fi[i].hoten,fi[i].sdt,fi[i].email);
    }
    int i=1;
    for(node p = head; p != NULL; p = p->next){
        fprintf(dr,"%d. ho va ten: %s\n",i++,p->hoten);
        fprintf(dr,"sdt : %s\n",p->sdt);
        fprintf(dr,"gmail: %s\n\n",p->gmail);
    };
    printf("Thong tin da in ra file dau ra, vui long kiem tra tren file dau ra!\n");
    fclose(f);
    fclose(dr);
}
