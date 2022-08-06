# unordered_map
* unordered_map是一个将key和value关联起来的容器，它可以高效的根据单个key值查找对应的value。
## 基本操作
* 定义：#include <unordered_map>
* unordered_map<type,type> umap;
  * <string,int> umap;
  * <int,int> umap;
* 插入：umap.insert()
  * umap.insert("string",0);
  * umap.insert(0,0);
  * umap.insert(pair<string,int>("apple",2));
* 删除
  * 根据key删除,如果没找到n=0
  * auto n = umap.erase("test")   //删除
  * 删除会将该值变为0
* 更改
  * auto it = umap.find(key) //改
  * if(it != umap.end()) //存在的话
  * it->second = new_value; 
* 查找
  * 1.umap.find(x) != map.end()//查,返回下标
  * 2.if(umap.count(x) != 0) yes
## 样例
```c++
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> d;
    for(int i=1;i<=3;i++){
        string s;
        cin>>s;
        d[s]=i;
    }
    auto n = d.erase("asdf");//asdf对应的值会变成0
    string x;
    cin>>x;
    cout<<d[x]<<endl;
    cout<<d.size()<<endl;//删除不是真删除，只是归0,下标最后1开始
    cout<<n<<endl;
    for(auto t:d) cout<<t.second<<endl;
    return 0;
}
```
* unordered_map捆版表
  * //优先级表，将符号和等级关联
  ```c++
      unordered_map<char, int> h{ {'+', 1}, {'-', 1}, {'*',2}, {'/', 2} };
      char c="+",C="*";
      if(h[C]>h[c]) cout<<"yes"；
  ```