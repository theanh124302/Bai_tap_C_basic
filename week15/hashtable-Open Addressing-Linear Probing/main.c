#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 23
struct Hash {
    int value;
    int k;
};
typedef struct Hash *hash;
hash hashtable[SIZE];
int hashcode(int k) {
    return k % SIZE;
}

hash search(int k) {
    int i = hashcode(k);
    while(hashtable[i] != NULL) {
        if(hashtable[i]->k == k)
            return hashtable[i];
        ++i;
        i %= SIZE;
    }
    return NULL;
}

void insert(int k,int value) {
    hash p = (hash)malloc(sizeof(struct Hash));
    p->value = value;
    p->k = k;
    int i = hashcode(k);
    while(hashtable[i] != NULL && hashtable[i]->k != -1) {
        ++i;
        i %= SIZE;
    }
    hashtable[i] = p;
}
hash delete(hash p) {
    int k = p->k;
    int i = hashcode(k);
    while(hashtable[i] != NULL) {
        if(hashtable[i]->k == k) {
            hash a = hashtable[i];
            hashtable[i] = NULL;
            return a;
        }
        ++i;
        i %= SIZE;
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
    for(int i = 0; i<SIZE; i++) {
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
