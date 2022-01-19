#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define m 23
struct Hash {
    int value;
    int k;
};
int n=0;
typedef struct Hash *hash;
hash hashtable[25];
int hashcode1(int k) {
    while(k<0){
        k+=m;
    }
    return k % m;
}
int hashcode2(int k) {
    while((11-k)<0){
        k-=11;
    }
    return ((11-k) % 11);
}

hash search(int k) {
    int i = hashcode1(k);
    int j = hashcode2(k);
    while(hashtable[i] != NULL) {
        if(hashtable[i]->k == k)
            return hashtable[i];
        i=i+j;
        i %= m;
    }
    return NULL;
}

void insert(int k,int value) {
    /*if(n==25){
        printf("ham bam day!\n");
        return;
    }
    if(search(k)!=NULL){
        printf("khong them duoc phan tu do da ton tai key %d\n",k);
        return;
    }*/
    hash p = (hash)malloc(sizeof(struct Hash));
    p->value = value;
    p->k = k;
    int i = hashcode1(k);
    int j = hashcode2(k);
    while(hashtable[i] != NULL) {
        i=i+j;
        i %= m;
    }
    n++;
    hashtable[i] = p;
}
hash delete(hash p) {
    int k = p->k;
    int i = hashcode1(k);
    int j = hashcode2(k);
    while(hashtable[i] != NULL) {
        if(hashtable[i]->k == k) {
            hash a = hashtable[i];
            hashtable[i] = NULL;
            n--;
            return a;
        }
        i=i+j;
        i %= m;
    }
    return NULL;
}

int main() {
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
    for(int i = 0; i<25; i++) {
        if(hashtable[i] != NULL)
            printf("(%d,%d)\n",hashtable[i]->k,hashtable[i]->value);
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
}
