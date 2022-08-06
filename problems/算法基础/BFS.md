# BFS
## 概括
* 一层一层查找，类似草坪点火，向四个方向蔓延再蔓延
## 模板
```c++
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
//首先把四个方向捆绑
//其次用队列维护
queue<PII> q;
q.push({0,0});
while(q.size()){
    auto t = q.front();
    q.pop();//每次拿一个，递归；
    for(int i=0;i<4;i++){
    int a=x+d[i],b=y+dy[i];  
    //向四个方向走一遍
    if(0<=x&&x<n&&0<=y&&y<m&&g[x][y]==0&&d[x][y]==-1){//judge,同时先到的肯定短，d就不用比较了
        d[x][y]=d[t.first][t.second]+1;//初始化为-1；比上一个+1
        q.push({x,y});
    }
    }
    return d[n-1][m-1];//终点
}
```
## 例题
1. 走迷宫//https://www.acwing.com/problem/content/846/
* 题目概括：一张二维图只有0，1.0代表可以走，从左上走到右下，问最短移动几次，有多条，若没有则-1
//https://www.acwing.com/problem/content/846/
```c++
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>  
using namespace std;
typedef pair<int,int> PII;
const int N = 110;
int n,m;
int g[N][N],d[N][N];//g表示该点能不能走，d表示该点到0距离，初始化-1
int dx[4]={1,0,-1,0};//初始化
int dy[4]={0,1,0,-1};

int bfs(){
    queue<PII> q;//队列维护
    q.push({0,0});//初始化
    while(!q.empty()){//非空时
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){//4 way
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if(0<=x&&x<n&&0<=y&&y<m&&g[x][y]==0&&d[x][y]==-1){//judge,同时先到的肯定短，d就不用比较了
                d[x][y]=d[t.first][t.second]+1;//初始化为-1；
                q.push({x,y});
            }
        }
    }
    return d[n-1][m-1];//返回末尾
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(d,-1,sizeof(d));
    d[0][0]=0;
    cin>>n>>m;
    for(int j=0;j<n;j++)
        for(int i=0;i<m;i++)
            cin>>g[j][i];//all in 
    cout<<bfs()<<endl;
    return 0;
}
```
2. 八数码
* 题目概括：拼图，一个九宫格，有1-8和一个x每次只能把x和相邻的交换，问最少几次拼出正序，给出二维图
* 思路：当成一条字符串，用x=i/3,y=i%3来转换为二维，然后向四个方向交换，交换完也是一条字符串，存入队列，同时用count()判断是否存过，每次存的都是最字符串，用哈希表对应变到该字符串的次数

```c++
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>
using namespace std;
int bfs(string start){
    unordered_map<string,int> d;//能find同时计数
    queue<string> q;//维护
    string end = "12345678x";
    q.push(start);
    d[start]=0;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    while(q.size()){
        auto t = q. front();
        q.pop();
        if(t==end) return d[t];
        int distance = d[t];
        int k=t.find('x');
        int x=k/3,y=k%3;
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(0<=a&&a<3&&0<=b&&b<3){
                swap(t[a*3+b],t[k]);
                if(!d.count(t)){
                    q.push(t);
                    d[t]=distance+1;
                }
                swap(t[a*3+b],t[k]);
            }
        }  
    }
    return -1;
}
int main(){
    string start;
    for(int i=0;i<9;i++){
        char op;
        cin>>op;
        start+=op;
    }
    cout<<bfs(start)<<endl;
    return 0;
}
```