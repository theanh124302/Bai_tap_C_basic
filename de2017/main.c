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
typedef struct
{
    int doi1,doi2,diemdoi1,diemdoi2;
}trandau;
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
node input(char s[], int n)
{
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

void inputvongdau (node head, char s[], int n, trandau vong[][20])
{
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
    int dem1=0,a,doi,dem2=0;
    char d[2];
    while(s[i]!='\0'){
        dem1++;
        printf("vong %d : ",dem1);
        i+=6;
        dem2=0;
        while (1){
            if(s[i]=='v'||s[i]=='\0'){
                break;
            }
            if(s[i]=='\n'){
                printf("\n");
                doi=1;
                dem2++;
            }
            if(s[i]=='\t'){
                printf(" - ");
            }
            if(s[i]>47&&s[i]<58){
                d[0]=s[i];
                d[1]='\0';
                a=atoi(d);
                if(doi==2){
                    intendoi(head,a);
                    vong[dem1][dem2].doi2 = a;
                }
                if(doi==1){
                    intendoi(head,a);
                    vong[dem1][dem2].doi1 = a;
                    doi=2;
                }
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
void congbanthang(node head, int id, int diem)
{
    node p=head;
    while (p != NULL)
    {
        if (p->id == id)
                p->sobanthang = p->sobanthang +diem;
        p = p->next;
    }
}
void congbanthua(node head, int id, int diem)
{
    node p=head;
    while (p != NULL)
    {
        if (p->id == id)
                p->sobanthua = p->sobanthua + diem;
        p = p->next;
    }
}
void cong3diem(node head, int id)
{
    node p=head;
    while (p != NULL)
    {
        if (p->id == id)
                p->diem = p->diem + 3;
        p = p->next;
    }
}
void cong1diem(node head, int id)
{
    node p=head;
    while (p != NULL)
    {
        if (p->id == id)
                p->diem = p->diem + 1;
        p = p->next;
    }
}

void nhapthongtintrandau(int n, trandau vong[][20], node head)
{
    for(int i=1;i<n;i++){
        for(int j=1;j<=n/2;j++){
            printf("Nhap thong tin tran thu %d cua vong %d: ",j,i);
            intendoi(head,vong[i][j].doi1);
            printf(" : ");
            scanf("%d",&vong[i][j].diemdoi1);
            intendoi(head,vong[i][j].doi2);
            printf(" : ");
            scanf("%d",&vong[i][j].diemdoi2);
            congbanthang(head,vong[i][j].doi1,vong[i][j].diemdoi1);
            congbanthang(head,vong[i][j].doi2,vong[i][j].diemdoi2);
            congbanthua(head,vong[i][j].doi1,vong[i][j].diemdoi2);
            congbanthua(head,vong[i][j].doi2,vong[i][j].diemdoi1);
            if(vong[i][j].diemdoi1>vong[i][j].diemdoi2){
                cong3diem(head,vong[i][j].doi1);
            }
            if(vong[i][j].diemdoi1<vong[i][j].diemdoi2){
                cong3diem(head,vong[i][j].doi2);
            }
            if(vong[i][j].diemdoi1==vong[i][j].diemdoi2){
                cong1diem(head,vong[i][j].doi1);
                cong1diem(head,vong[i][j].doi2);
            }
        }
    }
    for(int i=1;i<n;i++){
        printf("Vong %d :\n",i);
        for(int j=1;j<=n/2;j++){
            intendoi(head,vong[i][j].doi1);
            printf(" - ");
            intendoi(head,vong[i][j].doi2);
            printf(" : %d - %d\n",vong[i][j].diemdoi1,vong[i][j].diemdoi2);
        }
    }
    in(head);
}

node loai(node head)
{
    node p=head;
    int diem=p->diem;
    while (p != NULL)
    {
        if (p->diem < diem)
                diem = p->diem;
        p = p->next;
    }
    while (p != NULL)
    {
        if (p->next->diem == diem)
                p->next=p->next->next;
        p = p->next;
    }
    return head;
}

int main()
{
    FILE *f = fopen("ds.txt","r");
    docfile(s,f);
    fclose(f);
    char c[2];
    c[0] = s[0];
    c[1] = '\0';
    int n = atoi(c),x;
    trandau vong[20][20];
    node head = NULL;
    int kiemtranhap=0;
    printf("CHUONG TRINH DA BONG \n1. Nap file\n2. In ra lich thi dau\n3. Cap nhat ket qua \n4. Thong ke\n5. Thoat.\n");
    while(1){
        printf("Hay chon tu 1 den 5.\n");
        fflush(stdin);
        scanf("%d",&x);
        if(x<1||x>5){
            printf("Vui long chon lai tu 1 den 5: ");
            fflush(stdin);
            scanf("%d",&x);
        }
        if(x==1){
            head = input(s,n);
            in(head);
            kiemtranhap = 1;
        }
        if(kiemtranhap==0){
            printf("Vui long nap file danh sach vao truoc khi muon thuc hien thao tac khac.\n");
            continue;
        }
        if(x==2){
            inputvongdau(head,s,n,vong);
        }
        if(x==3){
            nhapthongtintrandau(n,vong,head);
        }
        if(x==4){
            in(loai(head));
        }
        if(x==5){
            printf("Thoat!");
            break;
        }
    }
    return 0;
}
