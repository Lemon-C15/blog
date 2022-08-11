# Dijkstra
## 最短路径条数
* https://blog.csdn.net/cjj668/article/details/52723295?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-2-52723295-blog-119617433.pc_relevant_multi_platform_whitelistv1_exp2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-2-52723295-blog-119617433.pc_relevant_multi_platform_whitelistv1_exp2&utm_relevant_index=4
```c++
#include <bits/stdc++.h>
const int N=16;
 
int Calc(int G[N][N])
{
    int step[N];    //每个结点第几步可以到达
    int stepNumber[N];    //到每个节点有几种走法
    memset(step, 0, sizeof(int)*N);
    memset(stepNumber, 0, sizeof(int)*N);
    stepNumber[0]=1;
    queue<int> q;    //当前搜索的结点
    q.push(0);
    int from,i,s;
    while (!q.empty()) {
        from = q.front();
        q.pop();
        s=step[from]+1;
        for (i=1; i<N; i++) {      //0是起点，不遍历
            if (G[from][i]==1) {   //连通
                //i尚未可达或发现更快的路（权值不同才可能）
                if ((step[i]==0)||(step[i]>s)) {
                    step[i]=s;
                    stepNumber[i]=stepNumber[from];
                    q.push(i);
                }
                else if(step[i]==s){   //发现相同长度的路径
                    stepNumber[i]+=stepNumber[from];
                }
            }
        }
    }
    return stepNumber[N-1];
}
 
int main()
{
    int G[N][N];
    memset(G, 0, sizeof(int)*N*N);
    G[0][1]=G[0][4]=1;
    G[1][5]=G[1][0]=G[1][2]=1;
    G[2][1]=G[2][6]=G[2][3]=1;
    G[3][2]=G[3][7]=1;
    G[4][5]=G[4][0]=1;
    G[5][1]=G[5][4]=G[5][6]=G[5][9]=1;
    G[6][2]=G[6][5]=G[6][7]=G[6][10]=1;
    G[7][3]=G[7][6]=1;
    G[8][12]=G[8][9]=1;
    G[9][8]=G[9][13]=G[9][10]=1;
    G[10][9]=G[10][14]=G[10][11]=1;
    G[11][10]=G[11][15]=1;
    G[12][8]=G[12][13]=1;
    G[13][9]=G[13][12]=G[13][14]=1;
    G[14][10]=G[14][13]=G[14][15]=1;
    G[15][11]=G[15][14]=1;
 
    cout<<Calc(G)<<endl;
    return 0;
}
```
### 例题
* https://vjudge.net/contest/504321#problem/D
* 题目概括：一堆关系连线图，问1到x的最短路径的数是多少，有多条相同长度的但长度是最短的路
* 思路：Dijkstra和bfs求最短路径数
```c++
#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long int
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 7;
 
int Head[N], Edge[N], Next[N], idx;
void add(int a, int b) {//模拟链表
    idx++;//Edge 存储值
    Edge[idx] = b;//head对应有关系的坐标
    Next[idx] = Head[a];//关于a的链表
    Head[a] = idx;//下标
    //多条链表，每个点能走的点
}
 
int n, m;
int dis[N], cnt[N];//距离和条数
int vis[N];//0 or 1//标志是否走过
void bfs(int s) { 
    queue<int> q;//队列
    //初始化
    dis[s] = 0;//距离
    q.push(s);//入队
    vis[s] = 1;//mark
    cnt[s] = 1;//最短条数
    //
    while (!q.empty()) {//非空时
        int t = q.front();//引用第一个
        q.pop();//弹出
        for (int i = Head[t]; ~i; i = Next[i]) {//条件是i！=-1
            int e = Edge[i];//Edge对应的值//i代表各个下标，下标都在head[t]里面，head[t]是t点对于的其他连线的集合
            if (!vis[e]) {//未经过该点
                dis[e] = dis[t] + 1;//能到该点，距离是上一个的距离+1
                cnt[e] = cnt[t];//到这里的路径数目和上一个点相同，因为第一次到
                q.push(e);//in
                vis[e] = 1;//sign
            } 
            else if (vis[e] && dis[e] == dis[t] + 1)////到过且距离相等但不是之前的路
                cnt[e] = (cnt[e] + cnt[t]) % mod;//路径数相加
        }
    }
}
signed main() {
    mem(Head, -1);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    bfs(1);//从1出发 
    cout << cnt[n] << endl;//到n点
    return 0;
}
```