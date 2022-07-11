# funtion：

* 1.rotate(left,mid,right);
  //使数组或向量往后退，最后一个到前面，循环几次看mid和right差值，left和right表范围

* 2.int tolower(int c);
  //大小写转换.函数说明：若参数 c 为 大写字母 则将该对应的小写字母返回。
  ```c++
  #include <ctype.h>
  #include <stdio.h>
  
  int main() {
    char s[] = "aBcDeFgH12345;!#$";
  
    printf("before tolower() : %s\n", s);
    for (int i = 0; i < sizeof(s); i++) {
      s[i] = tolower(s[i]);
    }
    printf("after tolower() : %s\n", s);
  
    return 0;
  }
  //before tolower() : aBcDeFgH12345;!#$
  //after tolower() : abcdefgh12345;!#$
  ```
* 3.str=str.replace(str.find("a"),2,"#");//find返回下标
  //从第一个a位置开始的两个字符替换成#，取代 he is@ a@ good boy -> he is@ # good boy

* 4.#define rep(i,a,b) for(int i=a;i<=b;i++)
    #define nrep(i,a,b) for(int i=a;i>=b;i--)
    //自定义函数

# useful： 
* s[]的长度，i<sizeof(s)可简单遍历
* for(auto &x : p) cout<<x<<endl //遍历p向量/数组里的所有且引用，让x==it；
* for(auto x ： p) cout<<x<<endl //遍历但不改变值
* unique(a.begin(),a.end());//去重,将重复的元素移动到最后,返回尾巴后一个，
重复元素第一个的坐标，是个迭代器
* a.erase(unique(a.begin,a.end()),a.end);此时把尾巴删掉
* sort排序
  * sort(a,a+n);数字
  * sort默认小到大
  * greater使内置函数从大到小排序，而less使的内置函数从小到大排序。
  * sort(a,a+10,greater());
  * sort(a,a+10,less()); 
  * //priority_queue用法如下：从小到大
    * priority_queue<int,vector,greater >que;
    * priority_queue <ll,vector<ll>,greater<ll> > pq; 

# knowledge point
## STL
* q.emplace(i,j)//将 i 插入到 j 位置
* q.top().first //返回第一个值
* s[]是全局变量，会自动初始化成0


## signed main
 ```c++
#define ll long long//新定义
  int main(){
      ll int x;
      scanf("%lld",&x);
  }
  
  #define int long long新定义
  signed main(){
    ...
  }
  ```
## std :: cout
* std 就是你没有using namespace std;时int main 里的每一句都要加std：：不然就会运行错误
## 素数
* 求素数边界不用n,用sqrt(n),缩小范围
* 素数筛法，筛选1到maxn的素数
```c++
void prim(){//if每一个数都要判断一遍，太慢了
    for(int i=2;i<maxn;i++) vis[i]=1;//初始化1
    vis[0]=vis[1]=0;
    top=0;
    for(int i=2;i<maxn;i++){
        if(vis[i]==1){
            prime[++top]=i;//数组
            for(int j=2*i;j<maxn;j+=i) vis[j]=0;
        }
    }
}
```