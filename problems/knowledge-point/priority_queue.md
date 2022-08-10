# priority_queue(优先队列)
## 概念
* 可以以o(log n) 的效率查找一个队列中的最大值或者最小值，其中是最大值还是最小值是根据创建的优先队列的性质来决定的。
* 优先队列有三个参数，其声明形式为：priority_queue< type, container, function >
* 这三个参数，后面两个可以省略，第一个不可以。
    * type：数据类型；
    * container：实现优先队列的底层容器，默认(vector)；
        * 对于container，要求必须是数组形式实现的容器，例如vector、deque，而不能使list。
    * function：元素之间的比较方式,(默认最大堆)；
        * priority_queue<int> big_heap; (big)
        * priority_queue<int,vector<int>,greater<int> > small_heap;  (small)//注意空格，不然变成右移运算符
## 样例
### 基本类型
```c++
#include<iostream>
#include <queue>
using namespace std;
int main()
{
    //对于基础类型 默认是大顶堆
    priority_queue<int> a;
    //等同于 priority_queue<int, vector<int>, less<int> > a;

    //      这里一定要有空格，不然成了右移运算符↓↓
    priority_queue<int, vector<int>, greater<int> > c;  //这样就是小顶堆
    priority_queue<string> b;//string 类型

    for (int i = 0; i < 5; i++)
    {
        a.push(i);
        c.push(i);
    }
    while (!a.empty())
    {
        cout << a.top() << ' ';
        a.pop();//top顶先出
    }//out:4 3 2 1 0
    cout << endl;

    while (!c.empty())
    {
        cout << c.top() << ' ';
        c.pop();
    }//out:0 1 2 3 4
    cout << endl;

    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty())
    {
        cout << b.top() << ' ';
        b.pop();
    }//out:cbd abcd abc
    cout << endl;
    return 0;
}
```
### pair做优先队列
```c++
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    priority_queue<pair<int, int> > a;//big
    pair<int, int> b(1, 2);
    pair<int, int> c(1, 3);
    pair<int, int> d(2, 5);
    a.push(d);
    a.push(c);
    a.push(b);
    while (!a.empty())
    {
        cout << a.top().first << ' ' << a.top().second << '\n';
        a.pop();
    }
    /*out:
    2 5
    1 3
    1 2
    */
}
```