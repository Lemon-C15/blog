# Dijkstra(迪杰斯特拉)
* 应用：一种求解非负权图上单源最短路径的算法（单向）
## 流程
1. 分两个集合。一个已确定到1点的最短路的点，一个未确定到1点的最短路的点
2. 在未确定的点集挑一个**最短**的，初始化时1到1的距离是0，其他都是无穷，一般挑1
3. 对这个点的所以关联的点求最短路，即1到这个点的距离加上这个点到关联点的距离，与1到关联点的距离比较，一般初始化未无穷，选小的
4. 把该点放入已确定距离的集合，通过标记判断
5. 重复n次
## 例题
* 数多分布散用邻接表，数小分布密集用邻接表，否则容易超时
### 朴素版
1. n*2n思路模板，邻接矩阵维护
```c++
//https://www.acwing.com/problem/content/851/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 510;
int d[N][N];//矩阵
bool st[N];
int dis[N];
int n , m ;
int dijkstra(){
    memset(dis,0x3f,sizeof(dis));//memset函数不是初始化为0x3f，而是2的0x3f方
    dis[1]=0;//一开始定义最小
    for(int j=1;j<=n;j++){
        int t;
        int mind=0x3f3f3f3f;
        for(int i=1;i<=n;i++)//find min
            if(!st[i]&&dis[i]<mind) t=i,mind=dis[i];
        st[t]=true;//mark
        for(int i=1;i<=n;i++){//全部重新连接
            dis[i]=min(dis[i],dis[t]+d[t][i]);
        }
    }    
    if(dis[n]==0x3f3f3f3f) return -1;
    return dis[n];
}
int main(){
    cin>>n>>m;
    memset(d,0x3f,sizeof d);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        d[a][b]=min(d[a][b],c);//去重留短
    }
    cout<<dijkstra()<<endl;
    return 0;
}
```
2. 结构体和vector做邻接矩阵
```c++
//https://www.acwing.com/problem/content/851/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
const int N = 510;
struct edge{
    int v,w;
};
vector<edge> e[N];//邻接表
int dis[N],vis[N];//距离和搜索标记
void dijkstra(int n,int s){
    memset(dis,63,sizeof(dis));//memset二进制63位初始化为一个大数
    dis[s]=0;//到起点1
    for(int i=1;i<=n;i++){
        int u=0,mind=0x3f3f3f3f;
        for(int j=1;j<=n;j++){//find the min
            if(!vis[j]&&dis[j]<mind) u=j,mind=dis[j];
        }
        vis[u]=true;//mark
        for(auto ed:e[u]){//只找和u有关系的，不全部找
            int v=ed.v,w=ed.w;//v是u的连线点，w是距离
            if(dis[v]>dis[u]+w) dis[v]=dis[u]+w;
        }//u到v的距离小于现在的u到v的距离
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b,c;
        edge temp;//临时变量
        cin>>a>>b>>c;
        temp.v=b;
        temp.w=c;
        e[a].push_back(temp);
    }
    dijkstra(n,1);
    //for(auto it=e[1].begin();it!=e[1].end();it++) cout<<(*it).v<<" "<<(*it).w<<endl;
    if(vis[n]) cout<<dis[n];
    else cout<<-1;
    return 0;
}
```
### 优化版
* 优先队列优化,针对超级大数1e9，边权关系用pair维护，邻接表作图
```c++
//https://www.acwing.com/problem/content/description/852/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
const int N = 150010;
int n , m ; 
int w[N],h[N],ne[N],e[N],idx;//w为权
bool st[N];
int dis[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dijkstra(){//此时dis=0x3f3f3f3f
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    priority_queue<PII,vector<PII>,greater<PII> > heap;//small
    heap.push({0,1});
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second,distance=t.first;
        if(st[ver]) continue;
        st[ver]=true;
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j=e[i];//value
            if(dis[j]>dis[ver]+w[i])//当前的1到此的大于1到上一个点加上一个点到这个点的距离
            {
                dis[j]=dis[ver]+w[i];
                heap.push({dis[j],j});
            }
        }
    }
    if(dis[n]==0x3f3f3f3f) return -1;
    else return dis[n];
}
int main(){

    memset(h,-1,sizeof(h));
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<dijkstra();
    return 0;
}
```