#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct link
{
    int diem;
    char doibong[30];
    struct link *left, *right;
};
typedef struct link *node;
int kiemtranhap = 0, sodoixuonghang=0, diemxuonghang, luachon, demsodoi;
node newnode(char a[])
{
    node temp = (node )malloc(sizeof(struct link));
    temp->diem = 0;
    strcpy(temp->doibong,a);
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(node root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%20s %10d\n", root->doibong, root->diem);
        inorder(root->right);
    }
}

void inorderfile(node root, FILE *kq)
{
    if (root != NULL) {
        inorderfile(root->left,kq);
        fprintf(kq,"%s\t%d\n", root->doibong, root->diem);
        inorderfile(root->right,kq);
    }
}

node insert(node root, char a[])
{
    if (root == NULL) return newnode(a);
    if (strcmp(root->doibong,a)>0)
        root->left = insert(root->left, a);
    else
        root->right = insert(root->right, a);
    return root;
}
node minValueNode(node root)
{
    node current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
node deleteNode(node root, char a[])
{
    if (root == NULL) return root;
    if (strcmp(root->doibong,a)>0)
        root->left = deleteNode(root->left, a);
    else if (strcmp(root->doibong,a)<0)
        root->right = deleteNode(root->right, a);
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
        strcpy(root->doibong,temp->doibong);
        root->diem=temp->diem;
        root->right = deleteNode(root->right, temp->doibong);
    }
    return root;
}
node Search(node root, char a[] )
{
    if ( root == NULL ){
        return NULL;
    }
    if(strcmp(root->doibong,a)==0){
        return root;
    }else if (strcmp(root->doibong,a)>0){
        return Search(root->left, a );
    }else if(strcmp(root->doibong,a)<0){
        return Search(root->right, a );
    }
}


node cong3diem(node root, char a[])
{
    node p = Search(root,a);
    p->diem+=3;
    return root;
}
node cong1diem(node root, char a[])
{
    node p = Search(root,a);
    p->diem+=1;
    return root;
}
int diemcaonhat(node root)
{
    if(root==NULL){
        return 0;
    }
    int dcn=root->diem;
    int a = diemcaonhat(root->left);
    int b = diemcaonhat(root->right);
    if(a>dcn){
        dcn=a;
    }
    if(b>dcn){
        dcn=b;
    }
    return dcn;
}


node docfile(FILE *f)
{
    node root=NULL;
    char ten1[100],ten2[100],diem1[100],diem2[100];
    while (fscanf(f,"%s %s %s %s",ten1,ten2,diem1,diem2)!=EOF){
        if(Search(root,ten1)==NULL){
            root = insert(root,ten1);
            printf("Da them doi %s \n",ten1);
            demsodoi++;
            printf("Day la doi duoc them thu %d\n",demsodoi);
        }
        if(Search(root,ten2)==NULL){
            root = insert(root,ten2);
            printf("Da them doi %s \n",ten2);
            demsodoi++;
            printf("Day la doi duoc them thu %d\n",demsodoi);
        }
        if(atoi(diem1)>atoi(diem2)){
            root = cong3diem(root,ten1);
        }
        if(atoi(diem1)<atoi(diem2)){
            root = cong3diem(root,ten2);
        }
        if(atoi(diem1)==atoi(diem2)){
            root = cong1diem(root,ten1);
            root = cong1diem(root,ten2);
        }
    }
    return root;
}
void xuonghang(node root, node p, int dxh)
{
    if (p != NULL) {
        if(p->diem<dxh){
            printf("%20s%10d\n",p->doibong,p->diem);
            sodoixuonghang++;
            root = deleteNode(root,p->doibong);
            p=root;
        }
        xuonghang(root,p->left,dxh);
        xuonghang(root,p->right,dxh);
    }
}

int main()
{
    FILE *f = fopen("file.txt","r");
    FILE *kq = fopen("ketqua.txt","w+");
    node root = NULL;
    int xh=0;
    char madoi[20];
    printf("CHUONG TRINH PHAT QUA CHO CAC EM NHO\n1. Nap vao file\n2. Inorder\n3. Tim kiem doi bong\n4. Cac doi xuong hang\n5. Xuat file.\n6. Thoat.\n");
    while(1){
        printf("\nHay chon tu 1 den 6.\n");
        fflush(stdin);
        scanf("%d",&luachon);
        if(luachon==1&&kiemtranhap==1){
            printf("Ban da nap file, vui long chon tac vu khac hoac thoat ra de nap file moi.\n");
            continue;
        }
        if(luachon<1||luachon>6){
            printf("\nVui long chon lai tu 1 den 6: ");
            fflush(stdin);
            scanf("%d",&luachon);
        }
        if(luachon==1){
            root = docfile(f);
            kiemtranhap=1;
        }
        if(kiemtranhap==0){
            printf("\nVui long nap file danh sach vao truoc khi muon thuc hien thao tac khac.\n");
            continue;
        }
        if(luachon==2){
            printf("%20s %10s\n","Ma so doi bong","Diem");
            inorder(root);
        }
        if(luachon==3){
            printf("\nVUi long nhap ma cua doi bong :\n");
            fflush(stdin);
            gets(madoi);
            if(Search(root,madoi)==NULL){
                printf("Khong co doi bong nay!\n");
            }
            else{
                printf("Diem so cua doi %s la %d\n",madoi,Search(root,madoi)->diem);
            }
        }
        if(luachon==4){
            printf("\nVui long nhap diem xuong hang :\n");
            fflush(stdin);
            scanf("%d",&diemxuonghang);
            while(1){
                if(diemxuonghang<=0){
                    printf("Diem khong hop le, vui long nhap lai diem > 0 :\n");
                    fflush(stdin);
                    scanf("%d",&diemxuonghang);
                }
                if(diemxuonghang>=diemcaonhat(root)){
                    printf("Diem cao the giai sau xo giay vao ma da, vui long nhap lai diem < %d :\n",diemcaonhat(root));
                    fflush(stdin);
                    scanf("%d",&diemxuonghang);
                }
                if((diemxuonghang>0) && (diemxuonghang<=diemcaonhat(root))){
                    break;
                }
            }
            sodoixuonghang=0;
            printf("Cac doi phai xuong hang la :\n");
            node p = root;
            xuonghang(root,p,diemxuonghang);
            if(sodoixuonghang==0){
                printf("Khong co doi nao phai xuong hang ca :v\n");
            }
            printf("Cac doi con lai la :\n");
            inorder(root);
            xh=1;
            if(root->right==NULL&&root->left==NULL){
                printf("Con duy nhat 1 doi nen giai da giai tan, cam on!\n");
                luachon=5;
            }
        }
        if(luachon==5){
            if(xh==1){
                printf("Da xuat kq ra file.\n");
                inorderfile(root,kq);
            }
            else{
                printf("Vui long thuc hien thao tac 4 truoc!\n");
                continue;
            }
        }
        if(luachon==6){
            printf("\nthoat.");
            break;
        }
    }
    fclose(f);
    fclose(kq);
}

