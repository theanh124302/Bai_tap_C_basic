#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define m 23
struct Hash {
    int value;
    int k;
    struct Hash *next;
};
int n=0;
typedef struct Hash *hash;

int hashcode(int k) {
    return k % m;
}
hash hashtable[23];
void creat()
{
    for (int i=0;i<23;i++){
        hashtable[i]=NULL;
    }
}
hash search(int k) {
    int i = hashcode(k);
    if(hashtable[i]==NULL){
        return NULL;
    }
    hash p = hashtable[i];
    while(p != NULL) {
        if(p->k == k)
            return p;
        p = p->next;
    }
    return NULL;
}

void insert(int k,int value) {
    if(search(k)!=NULL){
        printf("khong them duoc phan tu do da ton tai key %d\n",k);
        return;
    }
    hash a = (hash)malloc(sizeof(struct Hash));
    a->value = value;
    a->k = k;
    a->next = NULL;
    int i = hashcode(k);
    if (hashtable[i]==NULL){
        hashtable[i]=a;
        return;
    }
    hash p = hashtable[i];
    while(p->next != NULL) {
        p = p->next ;
    }
    p->next = a;
}
hash delete(hash a) {
    int k = a->k;
    int i = hashcode(k);
    if(hashtable[i] != NULL) {
        hash p = hashtable[i];
        if(p->k == k){
            hashtable[i]=p->next;
            p=NULL;
        }
        while(p != NULL) {
            if(p->next->k == k)
                p->next=p->next->next;
            p = p->next;
        }
    }
    return NULL;
}

int main() {
    creat();
    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);
    insert(7, 11);
    insert(3, 78);
    insert(25,1);
    insert(2,30);
    for(int i = 0; i<23; i++) {
        if(hashtable[i] != NULL){
            for(hash p = hashtable[i];p!=NULL;p=p->next){
                printf("(%d,%d) ",p->k,p->value);
            }
            printf("\n");
        }
        else
            printf(".........(trong) \n");
    }
    printf("\n");
    hash p = search(37);
    if(p != NULL) {
        printf("Gia tri cua phan tu can tim: %d\n", p->value);
    } else {
        printf("Khong tim thay\n");
    }
    delete(p);
    p = search(37);
    if(p != NULL) {
        printf("Gia tri cua phan tu can tim: %d\n", p->value);
    } else {
        printf("Khong tim thay\n");
    }
    for(int i = 0; i<23; i++) {
        if(hashtable[i] != NULL){
            for(hash p = hashtable[i];p!=NULL;p=p->next){
                printf("(%d,%d) ",p->k,p->value);
            }
            printf("\n");
        }
        else
            printf(".........(trong) \n");
    }
    printf("\n");
}
