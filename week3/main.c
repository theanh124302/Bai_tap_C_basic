#include <stdio.h>
#include <stdlib.h>
struct link
{
    char number[30];
    char name[30];
    char gmail[30];
    struct link *next;
};
typedef struct link *node;
node crt(){
    node a;
    int b;
    a = (node)malloc(sizeof(struct link));
    a->next = NULL;
    printf("phone number: ");
    fflush(stdin);
    scanf("%s",a->number);
    printf("name : ");
    fflush(stdin);
    scanf("%s",a->name);
    printf("gmail : ");
    fflush(stdin);
    scanf("%s",a->gmail);
    return a;
}
node ahead(){
    node head;
    head = NULL;
    return head;
}

node themdau(node head){
    node a = crt();
    if(head == NULL){
        head = a;
    }else{
        a->next = head;
        head = a;
    }
    return head;
}

node themcuoi(node head){
    node a,p;
    a = crt();
    if(head == NULL){
        head = a;
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = a;
    }
    return head;
}


node them(node head, int vitri){
    if(vitri == 0 || head == NULL){
        head = themdau(head);
    }else{
        int k = 1;
        node p = head;
        while(p != NULL && k != vitri){
            p = p->next;
            ++k;
        }

        if(k != vitri){
            head = themcuoi(head);
        }else{
            node a = crt();
            a->next = p->next;
            p->next = a;
        }
    }
    return head;
}

node xoadau(node head){
    if(head == NULL){
        printf("\list trong!");
    }else{
        head = head->next;
    }
    return head;
}
node xoacuoi(node head){
    if (head == NULL || head->next == NULL){
         return xoadau(head);
    }
    node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next;
    return head;
}

node xoa(node head, int vitri){
    if(vitri == 0 || head == NULL || head->next == NULL){
        head = xoadau(head);
    }else{
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != vitri){
            p = p->next;
            ++k;
        }

        if(k != vitri){
            head = xoacuoi(head);
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}



void in(node head){
    printf("\nDanh sach:\n");
    for(node p = head; p != NULL; p = p->next){
        printf("%s\n",p->number);
        printf("%s\n",p->name);
        printf("%s\n",p->gmail);
    }
}
node input(){
    node head = ahead();
    int n;
    do{
        printf("Nhap so luong dia chi n = ");
        scanf("%d", &n);
    }while(n <= 0);
    for(int i = 0; i < n; ++i){
        head = themcuoi(head);
    }
    return head;
}

void search(node head, char sdt)
{
    node p=head;
    while (p != NULL) /* go over all the list */
    {
        if (strcmp(p->number, sdt) == 0){
            return p;
        }

        p = p->next;
    }
    return NULL;
}




int main()
{
    node head = input();
    in(head);
    return 0;
}
