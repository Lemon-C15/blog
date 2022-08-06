# 哈希(Hash)
## 概念及应用
* 将一些大数通过取模**映射**到一个数组里
* 判断两个数是否在一个集合里
* 判断两个字符串是否相等
* 基本操作为插入和寻找
## 模拟散列表
* 基本的插入和寻找，对于取模产生的冲突用可以两种方式存储处理,基本取模是(x%N+N)%N，此时一定是正数
### 拉链法
* 对于每一个取模后的数开一个链表，用链表存储相同的哈希值对应的不同的原值，其中取模的N要设定为大于总数的第一个质数
```c++
//https://www.acwing.com/problem/content/842/
//记得初始化
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100003;
int h[N],e[N],ne[N],idx;//h[N]即是hash也是头节点
void insert(int x){//reflect
    int k=(x%N+N)%N;
    e[idx]=x;
    ne[idx]=h[k];//头节点插入
    h[k]=idx++;
}
bool find(int x){
    int k=(x%N+N)%N;//遍历
    for(int i=h[k];i!=-1;i=ne[i]){//指向下一个
        if(e[i]==x) return true;
    }
    return false;
}
int main(){
    int n;
    scanf("%d",&n);
    memset(h,-1,sizeof(h));//初始化边界是-1
    while(n--){
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(*op =='I') insert(x);
        else{
            if(find(x)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
```
### 开放寻址发
* 对于每一个冲突的数，选择往后找空的位置，位置一定是够的,如果到头就从头开始,对于每一个位置都继续初始化为0x3f3f3f3f
```c++
//https://www.acwing.com/problem/content/842/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 200003,null=0x3f3f3f3f;//自定义一个标志null
int h[N];
int find(int x){
    int t=(x%N+N)%N;
    while(h[t]!=null&&h[t]!=x){//可能已经录入，直到找到空的位置，有足够的位置
        t++;//找到null或者找到x,存和取
        if(t==N) t=0;//从t开始，到尾就跳到头继续遍历
    }
    return t;//t是x应该在的位置，h[t]要么是x，要么是0x3f
}
int main(){
    int n;
    scanf("%d",&n);
    memset(h,null,sizeof(h));//全部初始化为特定值
    while(n--){
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        int k=find(x);
        if(*op=='I') h[k]=x;
        else{
            if(h[k]!=null) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
```
## 字符串哈希
### 概括及应用
* 把字符串映射到整数的函数 𝑓，这个 𝑓 称为是 Hash 函数
* 在 Hash 函数值不一样的时候，两个字符串一定不一样；
* 可以用来比较字符串中的子字符串是否相同或者两条字符串匹配
### 方法
* 看成p进制数，第一个乘一个p，第二个乘2个p，本来应该第一个是最高位，所以计算的时候要补位数差，同时在一条字符串中的话，利用前缀和可以高效的计算某段的哈希值
* 用unsigned long long 可以直接处理哈希溢出
* P进制默认131
* 前缀和从1开始，字符字符串读入的时候也是1开始，用h[r]-h[l-1]*p[r-l+1]计算段落哈希值
```c++
//https://www.acwing.com/problem/content/843/
#include <iostream>
using namespace std;
typedef unsigned long long ULL;
const int N = 100010,P=131;
int n,m;
char str[N];
ULL h[N],p[N];//ULL,p表示倍数差
ULL get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];//左移p位,前缀和所以-1  
}
int main(){
    scanf("%d%d%s",&n,&m,str+1);//要+1，从1开始
    p[0]=1;//倍数
    for(int i=1;i<=n;i++){//应该是左边高位，但现在是右边高，所以左边要乘上倍数
        p[i]=p[i-1]*P;//通过倍数使两个数对齐
        h[i]=h[i-1]*P+str[i];//此时乘了P
    }
    while(m--){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get(l1,r1)==get(l2,r2)) puts("Yes");
        else puts("No");
    }
    return 0;
}
```