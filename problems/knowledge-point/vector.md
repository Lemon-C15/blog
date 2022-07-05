//1. 直接赋值
   - vector <int> A1 {1,2,3,4,5};               //一维
   -  vector <vector <int>> A2 {{1,2,3},{1,2,3}};//二维
   
//2. 不带参数构造
   - vector <int> A1;//空的数组,长度为0(size()为0)可以用A1.push_back(elem)输入元素
   
//3. 带参数构造
   - vector <int> A2(10);  //10个数据全为0
   - vector <int> A3(10,1);//10个数据全为1
   
//4. 通过同类型的vector初始化
   - vector <int> A1(5,1);
   - vector <int> A2(A1);  //通过A1来初始化A2

//5.通过地址访问
   - vector<int> A1 {1,2,3,4,5};        //一维
   - vector<int>::iterator k=A1.begin();//返回第一个元素的地址
   - cout<<*k<<endl;     //输出1
   - cout<<*(k+1)<<endl; //输出2
   - vector<int>::iterator k=A1.end();  //返回最后一个元素的下一位地址
   - cout<<*(k-1)<<endl; //输出5

//6.通过下标访问
   + vector<int> A1 {1,2,3,4,5}; //一维

   + cout<<A1.at(0)<<endl;       //输出为1
   
//7.添加,删除
   * A.pop_back();      //删除最后一个元素//只能删最后一个
   * A.push_back(elem); //在尾部添加一个元素

//8.特定位置插入删除
   - vector<int> A1 {1,2,3,4,5};        //一维
   - vector<int>::iterator k=A1.begin();//下标从0开始
   - A1.insert(k+1,9);                  //A1={1,9,2,3,4,5}
   - A1.erase(k+1);                     //A1={1,3,4,5}

//9.获取长度或者判断数组是否为空
   + vector<int> A1 {1,2,3,4,5};//一维
   + cout<<A1.size()<<endl;//输出5
   + cout<<A1.empty()<<endl;//输出0，空返回1
   + arr.front();返回的是第一个元素的引用。
   + arr.back();返回的的是最后一个元素的引用。

//10.other

    ///返回可用总元素
        A.capacity(); //返回A在内存中总共可以容纳的元素个数
        
    ///强制*调整*元素**个数**以及**数值 **   
        A.resize(10); //将A的现有元素个数调至10个，多则删，少则补，其值随机    
        A.resize(10,2); //将A的现有元素个数调至10个，多则删，少则补，其值为2
        
    ///将数组扩容    
        A.reserve(100); //将A的容量（capacity）扩充至100，也就是说现在测试A.capacity();的时候返回值是100.这种操作只有在需要给A添加大量数据的时候才显得有意义，因为这将避免内存多次容量扩充操作 ~~(当A的容量不足时电脑会自动扩容，当然这必然降低性能)~~ 
        
    ///将Vector数组A,B的元素进行整体交换   
        A.swap(B); //B为向量，将A中的元素和B中的元素进行整体性交换

# 11.use

   + include"algorithm"//要添加此头文件

      - （1）sort( A.begin() , A.end() ); //对a中的从A.begin()（包括它）到A.end()（不包括它）的元素进行从小到大排列

      + （2）reverse(A.begin(),A.end()); //对A中的从A.begin()（包括它）到A.end()（不包括它）的元素倒置，但不排列，如A中元素为1,3,2,4,倒置后为4,2,3,1

      - （3）copy(A.begin(),A.end(),B.begin()+1); //把A中的从A.begin()（包括它）到A.end()（不包括它）的元素复制到B中，从B.begin()+1的位置（包括它）开始复制，覆盖掉原有元素

      - （4）find(A.begin(),A.end(),10); //在A中的从A.begin()（包括它）到A.end()（不包括它）的元素中查找10，若存在返回其在向量中的位置

******
```c++

#include <bits/stdc++.h>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    int j;
    vector<int> a;
    for(int i=0;i<10;i++) a.push_back(i);//输入 
    cout<<a.at(1)<<endl；//输出下标所指
    a.pop_back();//尾巴out
    vector<int> ::iterator k=a.begin();//迭代使k=开始
    a.insert(k+5,0);//插入0
    a.erase(k);//删除下标所指
    cout<<a.size()<<endl;//长度
    cout<<a.capacity()<<endl;//返回可用内存
    sort(a.begin(),a.end());//排序
    reverse(a.begin(),a.end());//转置
    j=find(a.begin(),a.end(),5)-a.begin();//要减去开头坐标
    cout<<j<<endl;
    for(int i=0;i<9;i++) printf("%d ",a[i]);
    return 0;
}
```