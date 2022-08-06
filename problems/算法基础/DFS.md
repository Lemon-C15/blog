# DFS
* 概括：递归的，一步步的，用过以后要复原
## 例题
* 全排列
* https://www.acwing.com/problem/content/844/
1. 每次标记有没有被用过
```c++
#include <iostream>
//#define endl '\n'
using namespace std;

const int N = 10;

int n;
int path[N]; 
bool st[N];
void dfs(int u){
    if (u == n)
    {
        for (int i = 0; i < n; i ++ ) printf("%d ", path[i]);
        puts("");
        //cout<<endl;
        return;
    }

    for (int i = 1; i <=n; i ++ )
        if (!st[i])
        {
            path[u] = i;
            st[i]=true;//标记
            dfs(u + 1);
            st[i]=false;//复原
        }
}

int main(){
    scanf("%d", &n);

    dfs(0);

    return 0;
}
```
2. 每次交换一个到头，然后其他往后退一个
```c++
#include "stdio.h"
int n,a[15];

void move(int l){
    int i,j,tmp;
    if(l==n){
        for(int i=1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    else { 
        for(j=l;j<=n;j++){//千万注意开头是l，也就是和自己交换一次
            tmp=a[j];
            for(i=j;i>l;i--){//i是i，j是j,边界是l
                a[i]=a[i-1];//move to right
            }
            a[l]=tmp;
            move(l+1);
            for(i=l;i<j;i++){
                a[i]=a[i+1];//move to left
            }
            a[j]=tmp;
        } 
    }
}

int main(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        a[i]=i;
    }
    move(1);
}
```