# KMP
## 概念
* 字符串匹配算法
* 可以和自己或者另外一条字符串比较
* 如果是1条字符串用getnext一个就够了，自己和自己比较
## 例题
1. 
* asdfggh gh(in)
* 6(out)从1开始
```c++
#include <iostream>
#include<bits/stdc++.h>
#include<string.h>
char s1[1000],s2[1000];
using namespace std;
void getnext(char s[],int len,int next[]){//形参加[]
    int i=1,j=0;//取决于s从第几开始读
    //i=0,j=-1;
    next[1]=0;//next[0]=-1
    while(i<=len){//i<len
        if(j==0||s[j]==s[i]){//j==-1
            i++;
            j++;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }

}

int kmp(char s1[],int l1,char s2[],int l2,int next[]){
    int i=1,j=1;//保持相同///i=0;j=0
    while(i<=l1&&j<=l2){//条件//i<l1,j<l2
        if(j==0||s1[i]==s2[j]){//j==-1
            i++;
            j++;
        }
        else{
            j=next[j];//j[1]=0
        }
    }
    if(j>l2) return i-l2;//s2被读完//i+1-l2
    else return -1;
}
int main(){
    int l1,l2,i;
    
    int next[1000];
    scanf("%s %s",s1+1,s2+1);//s1,s2
    l1=strlen(s1+1);//(s1)
    l2=strlen(s2+1);//(s2)
    getnext(s2,l2,next);
    printf("%d",kmp(s1,l1,s2,l2,next));
}
```
2. 
* 包含多次，下标都输出，0开始
* https://www.acwing.com/problem/content/833/
```c++
输入样例：
3
aba
5
ababa
输出样例：
0 2
```c++
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int N = 1e6+10;
char s1[N],s2[N];
void getnext(int next[],int l2){
    int i=0,k=-1;
    next[0]=-1;
    while(i<l2){
        if(k==-1||s2[i]==s2[k]){
            i++;
            k++;
            next[i]=k;
        }
        else{
            k=next[k];
        }
    }
}

void kmp(int next[],int l1,int l2){
    int i=0,k=0;
    next[0]=-1;
    while(i<l1&&k<=l2){
        if(s1[i]==s2[k]||k==-1){
            i++;
            k++;
        }
        else{
            k=next[k];
        }
        if(k==l2){
            cout<<i-l2<<" ";
            k=next[k];
        }
    }   
    //else return -1;
}

int main(){
    int next[N];
    int l1,l2;
    cin>>l2;
    cin>>s2;
    cin>>l1;
    cin>>s1;
    getnext(next,l2);
    kmp(next,l1,l2);
    return 0;
}
```
3. 
* https://www.luogu.com.cn/problem/P3375
* 1. 多次输出符合的字符串的第一个元素的下标 ，从1开始
  2. 输出每个位置的前缀长度
* 思路：next数组表示的是前一个的前缀长度
```c++
in
ABABABC
ABA

out
1
3
0 0 1 
```
```c++
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int N = 1e5+10;
char s1[N],s2[N];
void getnext(int next[],int l2){
    int i=0,k=-1;
    next[0]=-1;
    while(i<l2){
        if(k==-1||s2[i]==s2[k]){
            i++;
            k++;
            next[i]=k;
        }
        else{
            k=next[k];
        }
    }
}

void kmp(int next[],int l1,int l2){
    int i=0,k=0;
    next[0]=-1;
    while(i<l1&&k<=l2){
        if(s1[i]==s2[k]||k==-1){
            i++;
            k++;
        }
        else{
            k=next[k];
        }
        if(k==l2){
            cout<<i-l2+1<<endl;
            k=next[k];
        }
    }   
    //else return -1;
}

int main(){
    int next[N];
    int l1,l2;
    cin>>s1;
    l1=strlen(s1);
    //cout<<l1<<endl;
    cin>>s2;
    l2=strlen(s2);
    getnext(next,l2);
    kmp(next,l1,l2);
    //next[1]=-1;
    for(int i=1;i<=l2;i++){//表示i之前的有多长，i=1表示i=0位置的前缀长度
        cout<<next[i]<<" ";       
    }
    return 0;
}
```