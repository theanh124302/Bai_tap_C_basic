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
        printf("(%d, %s )  ", root->key, root->dochoi);
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
void xoaphantutrung(arr array[], node root)
{
    int i=0;
    node p;
    while(array[i].key!=-1){
        p = Search(root,array[i].key);
        if(p!=NULL){
            printf("\nEm nho bi trung : %d - %s \n",p->key, p->dochoi);
            deleteNode(root,p->key);
            return;
        }
        i++;
    }
}
void chenmangcautrucvaocay(arr array[], node root)
{
    int i=0;
    while(array[i].key!=-1){
        insert(root,array[i].key,array[i].ten);
        i++;
    }
}



int main()
{
    char a,sa[1000];
    arr array[100];
    int i=0;
    FILE *fa = fopen("fileA.txt","r");
    while (fscanf(fa,"%c",&a)!=EOF){
        sa[i]=a;
        i++;
    }
    fclose(fa);
    sa[i]='\0';
    char b,sb[1000];
    i=0;
    FILE *fb = fopen("fileB.txt","r");
    while (fscanf(fb,"%c",&b)!=EOF){
        sb[i]=b;
        i++;
    }
    fclose(fb);
    sb[i]='\0';
        for(i=0;i<100;i++){
        array[i].key=-1;
    }
    node root =NULL;
    int kiemtranhapA=0,kiemtranhapB=0,n;
    printf("CHUONG TRINH PHAT QUA CHO CAC EM NHO\n1. Nhap vao file A\n2. Nhap vao file B\n3. Xoa phan tu trung voi mang tren cay nhi phan\n4. Chen them mang vao cay nhi phan\n5. Thoat.\n");
    while(1){
        printf("\nHay chon tu 1 den 5.\n");
        fflush(stdin);
        scanf("%d",&n);
        if(n<1||n>5){
            printf("\nVui long chon lai tu 1 den 5: ");
            fflush(stdin);
            scanf("%d",&n);
        }
        if(n==1){
            root = docfileA(sa);
            printf("\nCay nhi phan sau khi nhap:\n");
            inorder(root);
            kiemtranhapA=1;
        }
        if(n==2){
            docfileB(sb,array);
            printf("\nMang sau khi nhap:\n");
            i=0;
            while(array[i].key!=-1){
                printf("(%d %s) ",array[i].key,array[i].ten);
                i++;
            }
            kiemtranhapB=1;
        }
        if((n!=1&&n!=2)&&n!=5){
            if(kiemtranhapA==0){
                printf("\nVui long nap file A danh sach vao truoc khi muon thuc hien thao tac khac.\n");
                continue;
            }
            if(kiemtranhapB==0){
                printf("\nVui long nap file B danh sach vao truoc khi muon thuc hien thao tac khac.\n");
                continue;
            }
        }
        if(n==3){
            xoaphantutrung(array,root);
            printf("\ncay nhi phan sau khi xoa la :\n");
            inorder(root);
        }
        if(n==4){
            chenmangcautrucvaocay(array,root);
            printf("\ncay nhi phan sau khi chen them :\n");
            inorder(root);
        }
        if(n==5){
            printf("\nthoat.");
            break;
        }
    }
}
