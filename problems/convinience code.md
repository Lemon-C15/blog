# funtion：

* 1.rotate(left,mid,right);
  //使数组或向量往后退，最后一个到前面，循环几次看mid和right差值，left和right表范围

* 2.tolower（）
  //大小写转换

* 3.str=str.replace(str.find("a"),2,"#");
  //从第一个a位置开始的两个字符替换成#，取代 he is@ a@ good boy -> he is@ # good boy

* 4.#define rep(i,a,b) for(int i=a;i<=b;i++)
    #define nrep(i,a,b) for(int i=a;i>=b;i--)
    //自定义函数

# useful： 

* for(auto &x : p) cout<<i<<endl //遍历p向量/数组里的所有且引用，让x==it；
* for(auto x ： p) cout<<i<<endl //遍历但不改变值

# knowledge point
## STL
* q.emplace(i,j)//将 i 插入到 j 位置
* q.top().first //返回第一个值

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

