//模拟每个)对应的(的位置输出即可
让)(为一组输出
```C++
#include <bits/stdc++.h>
using namespace std;

int a[100010];
int main(){
    int n,i;
    scanf("%d",&n);
    char str[100010];
    scanf("%s",str+1);//从1 开始
    stack<int> st;//用栈存放(及序号
    for(i=1;i<=n;i++){
        if(str[i]=='('){
            st.push(i);//存放（的序号
        }
        else if(str[i]==')'){
            a[i]=st.top();//拿取最近一个(的序号放到这个时候的i**对应的**a[i]里面；
            st.pop();//弹出
        }
    }
    for(i=1;i<=n;i++){
        if(str[i]=='(') continue;//)and(一起输出
        else if(str[i]==')'){
            printf("%d %d ",i,a[i]);//先 )再(
        }
        else{
            printf("%d ",i);
        }
    }
    return 0;
}
```