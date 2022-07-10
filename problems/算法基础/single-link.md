# 单链表
## 模板
1. 动态链表 ，一般不用，因为非常慢，一般用单链表写邻接表，模拟链表，邻接表可以存储图和数
```c++
struct node{
    int data;
    node *next;
}

for(){
    p=new(node);
    ......
}
```
2. 模拟链表//速度快,静态链表
```c++
#include <iostream>
using namespace std;
const int N= 1e5+10;
//head表示头结点的下标
//e[i]表示结点i的值
// ne[i]表示i结点next的指针是多少
//idx表示当前用到那个点，不断往下开
int head,e[N],ne[N],idx;
//初始化
void init(){
    idx=0;
    head=-1;
}
//将x插入到头结点
void add_to_head(int x){
    e[idx]=x,ne[idx]=head,head=idx,idx++;
}
//将x插入到k后面
void add(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}
//删除k后面那个数
void remove(int k){
    ne[k]=ne[ne[k]];
}
```