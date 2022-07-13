
abc,,de,g,,f,,,前序
输出中序后序
```c++
#include <bits/stdc++.h>
using namespace std;
char a[55];
int i;
typedef struct Tree{//用链表
    char data;
    Tree *left;
    Tree *right;
}*Bitree;//指针类型，可在结构体外面用

Bitree creat(){//一直先找左节点
    Bitree root;//不加*
    char c=a[i++];//进函数++//遍历a数组
    if(c==','){
        root=NULL;//空节点
    }
    else{
        root=(Bitree)malloc(sizeof(Bitree));
        root->data=c;
        root->left=creat();//循环
        root->right=creat();//右节点找玩返回
    }
    return root;
}

void zhong(Bitree root){
    if(root){
        zhong(root->left);
        printf("%c",root->data);
        zhong(root->right);
    }
}

void hou(Bitree root){
    if(root){
        hou(root->left);
        hou(root->right);
        printf("%c",root->data);
    }
}

int main(){
    Bitree root;
    while(~scanf("%s",a)){
        i=0;
        root=creat();
        zhong(root);
        printf("\n");
        hou(root);
        printf("\n");
    }
   return 0;
}
```