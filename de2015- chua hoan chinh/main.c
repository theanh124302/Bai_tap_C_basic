#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct link
{
    int key;
    char dochoi[30];
    struct link *left, *right;
};
typedef struct link *node;
struct ARR
{
    int key;
    char ten[30];
};
typedef struct ARR arr;
node newnode(int k, char a[])
{
    node temp = (node )malloc(sizeof(struct link));
    temp->key = k;
    strcpy(temp->dochoi,a);
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(node root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("(%d, %s ) -> ", root->key, root->dochoi);
        inorder(root->right);
    }
}
node insert(node root, int key, char a[])
{
    if (root == NULL) return newnode(key,a);
    if (key < root->key)
        root->left = insert(root->left, key,a);
    else
        root->right = insert(root->right, key,a);
    return root;
}
node minValueNode(node root)
{
    node current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
node deleteNode(node root, int key)
{
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            node temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node temp = root->left;
            free(root);
            return temp;
        }
        node temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
node Search(node root, int key )
{
    if ( root == NULL )
        return NULL;
    if(root->key == key){
        return root;
    }else if (root->key>key){
        return Search(root->left, key );
    }else if(root->key<key){
        return Search(root->right, key );
    }
}
node docfileA(char s[])
{
    node root = NULL;
    char maso[100], ten[100];
    int x=0,dem=0,i=0;
    while(1){
        if (s[i]=='\n'){
            ++i;
            ++dem;
        }
        if (s[i]=='\0'){
            break;
        }
        x=0;
        while (s[i]!='\t'){
            maso[x]=s[i];
            x++;
            i++;
        }
        i++;
        maso[x]='\0';
        x=0;
        while (s[i]!='\n'){
            ten[x]=s[i];
            x++;
            i++;
        }
        ten[x]='\0';
        if(x==0){
            printf("Ma so %s van chua co qua, vui long nhap them : ",maso);
            fflush(stdin);
            gets(ten);
            fflush(stdin);
        }
        root = insert(root, atoi(maso),ten);
    }
    return root;
}



void docfileB(char s[], arr array[])
{
    char maso[100], ten[100];
    int x=0,dem=0,i=0;
    while(1){
        if (s[i]=='\n'){
            ++i;
            ++dem;
        }
        if (s[i]=='\0'){
            break;
        }
        x=0;
        while (s[i]!='\t'){
            maso[x]=s[i];
            x++;
            i++;
        }
        i++;
        maso[x]='\0';
        x=0;
        while (s[i]!='\n'){
            ten[x]=s[i];
            x++;
            i++;
        }
        ten[x]='\0';
        if(x==0){
            printf("Ma so %s van chua co qua, vui long nhap them : ",maso);
            fflush(stdin);
            gets(ten);
            fflush(stdin);
        }
        array[dem].key = atoi(maso);
        strcpy(array[dem].ten,ten);
    }
}
void timkiem(arr array[], node root)
{
    int i=0;
    node p;
    while(&array[i].key!=NULL){
        p = Search(root,array[i].key);
        if(p!=NULL){
            printf("%d - %s \n",p->key, p->dochoi);
            deleteNode(root,p->key);
        }
        i++;
    }
}

int main()
{
    char a,s[1000];
    int i=0;
    FILE *f = fopen("ds.txt","r");
    while (fscanf(f,"%c",&a)!=EOF){
        s[i]=a;
        i++;
    }
    fclose(f);
    s[i]='\0';
    node root = docfileA(s);
    arr array[100];
    docfileB(s,array);
    printf("In theo thu tu key: ");
    inorder(root);
    //timkiem(array,root);
}
