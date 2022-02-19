#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct link
{
    char diadiem[50];
    int gio;
    int phut;
    struct link *next;
};
typedef struct link *node;
node nodemoi(char a[], char b[], char c[])
{
    node p;
    p= (node)malloc(sizeof(struct link));
    p->next = NULL;
    strcpy(p->diadiem,a);
    p->gio = atoi(b);
    p->phut = atoi(c);
    return p;
}
node themdiadiem(node head, char a[], char b[], char c[])
{
    node x,p;
    x = nodemoi(a,b,c);
    if(head == NULL){
        head = x;
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = x;
    }
    return head;
}

node input(FILE *f){
    node head = NULL;
    char a[100],b[100],c[100];
    while (fscanf(f,"%s %s %s",a,b,c)!=EOF){
        head = themdiadiem(head,a,b,c);
    }
    return head;
}
void in(node head){
    printf("danh sach dia diem : \n%50s%10s%10s\n\n","Dia diem","Gio","Phut");
    for(node p = head; p != NULL; p = p->next){
        printf("%50s",p->diadiem);
        printf("%10d",p->gio);
        printf("%10d\n\n",p->phut);
    }
}
int timkiemdiadiem(node head)
{
    char a[50];
    printf("Nhap dia diem muon kiem tra: ");
    fflush(stdin);
    gets(a);
    node p=head;
    int dem = 0;
    while (p != NULL)
    {
        if (strcmp(p->diadiem, a) == 0){
            if(dem==0){
                printf("%d:%d",p->gio,p->phut);
            }
            else{
                printf(" , %d:%d",p->gio,p->phut);
            }
            dem++;
        }
        p = p->next;
    }
    if(dem==0){
        printf("Ban chua den day.");
    }
    printf("\n");
    return dem;
}
int timkiemthoigian(node head)
{
    int b,c;
    printf("Nhap gio: ");
    fflush(stdin);
    scanf("%d",&b);
    while(b<0||b>23){
        printf("Vui long nhap lai gio tu 0 den 23 : ");
        fflush(stdin);
        scanf("%d",&b);
    }
    printf("Nhap phut: ");
    fflush(stdin);
    scanf("%d",&c);
    while(c<0||c>59){
        printf("Vui long nhap lai gio tu 0 den 59 : ");
        fflush(stdin);
        scanf("%d",&c);
    }
    node p=head;
    while (p != NULL)
    {
        if (b==p->gio && c==p->phut){
            printf("%s",p->diadiem);
            printf("\n");
            return 1;
        }
        if (b<p->gio){
            printf("Khong tim thay lich su di chuyen\n");
            return 0;
        }
        p = p->next;
    }
    printf("Khong tim thay lich su di chuyen\n");
    return 0;
}
node xoa(node head)
{
    node p = head;
	p = p->next;
	free(head);
	return p;
}

void thongbao(node head)
{
    char a[50];
    int b,c;
    printf("Nhap dia diem f0 da den: ");
    fflush(stdin);
    gets(a);
    printf("Nhap gio: ");
    fflush(stdin);
    scanf("%d",&b);
    printf("Nhap phut: ");
    fflush(stdin);
    scanf("%d",&c);
    node p=head;
    while (p != NULL)
    {
        if ((b==p->gio && c==p->phut) && strcmp(p->diadiem, a) == 0){
            printf("Ban co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
            return;
        }
        if (b<p->gio){
            printf("Lich su di chuyen cua ban OK.\n");
            return;
        }
        p = p->next;
    }
    printf("Lich su di chuyen cua ban OK.\n");
}
void giaiphongvungnho(node head)
{
    int dem = 0;
    for(node p = head; p != NULL; p = p->next){
        dem++;
    }
    for(int i=0;i<dem;i++){
        head=xoa(head);
    }
    free(head);
    printf("Da thoat!\n");
}


int main()
{
    int n;
    FILE *f = fopen("ds.txt","r");
    node head;
    int kiemtranhap=0;
    printf("CHUONG TRINH TRUY VET COVID19\n1. Nap file log lich su di chuyen\n2. In ra lich su di chuyen\n3. Tim kiem lich su theo dia diem\n4. Tim kiem lich su theo thoi gian\n5. Kiem tra truy vet moi nhat\n6. Thoat.\n");
    while(1){
        printf("Hay chon tu 1 den 6.\n");
        fflush(stdin);
        scanf("%d",&n);
        if(n<1||n>6){
            printf("Vui long chon lai tu 1 den 6: ");
            fflush(stdin);
            scanf("%d",&n);
        }
        if(n==1){
            if(kiemtranhap==1){
                printf("Ban da nap vao file r, vui long chay lai de nap file moi.\n");
                break;
            }
            head = input(f);
            kiemtranhap = 1;
        }
        if(kiemtranhap==0){
            printf("Vui long nap file danh sach vao truoc khi muon thuc hien thao tac khac.\n");
            continue;
        }
        if(n==2){
            in(head);
        }
        if(n==3){
            timkiemdiadiem(head);
        }
        if(n==4){
            timkiemthoigian(head);
        }
        if(n==5){
            thongbao(head);
        }
        if(n==6){
            giaiphongvungnho(head);
            break;
        }
    }
    fclose(f);
    return 0;
}
