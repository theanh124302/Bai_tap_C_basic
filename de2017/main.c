#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct link
{
    char tendoibong[30];
    int id, diem, sobanthang, sobanthua;
    struct link *next;
};
char s[1000];
typedef struct link *node;
node nodemoi(char a[], char b[])
{
    node p;
    p= (node)malloc(sizeof(struct link));
    p->next = NULL;
    strcpy(p->tendoibong,a);
    p->id = atoi(b);
    p->diem = 0;
    p->sobanthang = 0;
    p->sobanthua = 0;
    return p;
}
node themdoibong(node head, char a[], char b[])
{
    node x;
    x = nodemoi(a,b);
    if(head == NULL){
        head = x;
    }else{
        x->next = head;
        head = x;
    }
    return head;
}
void docfile(char s[], FILE *f)
{
    int i=0;
    char x;
    while(fscanf(f,"%c",&x)!=EOF){
        s[i]=x;
        i++;
    }
    s[i]='\0';
}
node input(char s[]){
    char c[2];
    c[0] = s[0];
    c[1] = '\0';
    int n = atoi(c);
    node head = NULL;
    char ten[30],id[10];
    int i=1,x=0,dem=0;
    while(1){
        if (s[i]=='\n'){
            ++dem;
            ++i;
        }
        if (dem>n){
            break;
        }
        x=0;
        while (s[i]!='\t'){
            id[x]=s[i];
            x++;
            i++;
        }
        i++;
        id[x]='\0';
        x=0;
        while (s[i]!='\n'){
            ten[x]=s[i];
            x++;
            i++;
        }
        ten[x]='\0';
        head = themdoibong(head,ten,id);
    }
    return head;
}

void intendoi(node head, int x)
{
    node p=head;
    while (p != NULL)
    {
        if (p->id == x)
                printf("%s",p->tendoibong);
        p = p->next;
    }
}

void inputvongdau (node head, char s[])
{
    char c[2];
    c[0] = s[0];
    c[1] = '\0';
    int n = atoi(c);
    int i=0,dem=0;
    while(1){
        if(s[i]=='\n'){
            dem++;
        }
        if(dem>n){
            i++;
            break;
        }
        i++;
    }
    int dem1=0,a;
    char d[2];
    while(s[i]!='\0'){
        dem1++;
        printf("vong %d : ",dem1);
        i+=6;
        while (1){
            if(s[i]=='v'||s[i]=='\0'){
                break;
            }
            if(s[i]=='\n'){
                printf("\n");
            }
            if(s[i]=='\t'){
                printf(" - ");
            }
            if(s[i]>47&&s[i]<58){
                d[0]=s[i];
                d[1]='\0';
                a=atoi(d);
                intendoi(head,a);
            }
            i++;
        }
    }
}
void in(node head){
    printf("danh sach doi : \n%5s%30s\t%10s\t\t%10s\t%10s\n\n","Id","Ten","Diem","Ban Thang","Ban Thua");
    for(node p = head; p != NULL; p = p->next){
        printf("%5d",p->id);
        printf("%30s\t",p->tendoibong);
        printf("%10d\t\t",p->diem);
        printf("%10d\t",p->sobanthang);
        printf("%10d\n",p->sobanthua);
    }
}

int main()
{
    FILE *f = fopen("ds.txt","r");
    docfile(s,f);
    printf("%s",s);
    fclose(f);
    node head = input(s);
    in(head);
    inputvongdau(head,s);
    return 0;
}
