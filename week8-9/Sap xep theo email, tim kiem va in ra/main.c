/*We assume that you make a mobile phone’s address book.
•Declare a structure which can store at least "name", "telephone number", "e-mail address.”.
•Declare a structure for a binary tree which can stores the structure of an address book inside.
Read data of about 10 from an input file to this binary tree as the following rules.
–An address data which is smaller in the dictionary order for the e-mail address is stored to the left side of a node.
–An address data which is larger in the dictionary order for the e-mail address is stored to the right side of a node.
•(1) Confirm the address data is organized in the binary tree structure with some methods (printing, debugger, etc).
•(2) Find a specified e-mail address in the binary tree and output it to a file if found.
•(3) Output all the data stored in the binary tree in ascending order for the e-mail address. (Reserve it for the next week)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct link
{
    char email[30], sdt[30], name[30];
    struct link *left, *right;
};
typedef struct
{
    char name[20],email[20],sdt[20];
} st;
st fi[30];
typedef struct link *node;
node newnode(char a[], char b[], char c[])
{
    node temp = (node )malloc(sizeof(struct link));
    strcpy(temp->email,a);
    strcpy(temp->sdt,b);
    strcpy(temp->name,c);
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(node root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%20s %20s %20s\n",root->name, root->sdt, root->email);
        inorder(root->right);
    }
}

void inorderfile(node root, FILE *kq)
{
    if (root != NULL) {
        inorderfile(root->left,kq);
        fprintf(kq,"%20s %20s %20s\n",root->name, root->sdt, root->email);
        inorderfile(root->right,kq);
    }
}

node insert(node root, char a[], char b[], char c[])
{
    if (root == NULL) return newnode(a,b,c);
    if (strcmp(root->email,a)>0)
        root->left = insert(root->left, a,b,c);
    else
        root->right = insert(root->right, a,b,c);
    return root;
}
node Search(node root, char a[])
{
    if ( root == NULL ){
        return NULL;
    }
    if(strcmp(root->email,a)==0){
        return root;
    }else if (strcmp(root->email,a)>0){
        return Search(root->left, a );
    }else if(strcmp(root->email,a)<0){
        return Search(root->right, a );
    }
}

int main()
{
    char x,y[1000];
    node root =NULL;
    int demdong=0,demkytu=0;
    FILE *f=fopen("ds.txt","r+");
    FILE *gg=fopen("daura.txt","w+");
    while(fscanf(f,"%c",&x)!=EOF){
        if(x=='\n'){
            demkytu=0;
            demdong++;
            continue;
        }
        if(demdong%3==0){
            fi[demdong/3].name[demkytu]=x;
        }
        if(demdong%3==1){
            fi[demdong/3].sdt[demkytu]=x;
        }
        if(demdong%3==2){
            fi[demdong/3].email[demkytu]=x;
        }
        demkytu++;
    }
    int size=(demdong)/3;
    for(int i=0;i<size;i++){
        root = insert(root,fi[i].email,fi[i].sdt,fi[i].name);
    }
    inorder(root);
    printf("\n Hay nhap email muon tim : \n");
    fflush(stdin);
    gets(y);
    node e = Search(root,y);
    if(e==NULL){
        printf("\n Khong ton tai email nay!\n");
    }
    else{
        fprintf(gg,"Thong tin ban dang tim kiem :\n%20s %20s %20s\n\n\n",root->name, root->sdt, root->email);
        printf("\nDa in thong tin can tim ra file daura.txt, vui long kiem tra tren file.\n");
    }
    inorderfile(root,gg);
    fclose(f);
    fclose(gg);
}
