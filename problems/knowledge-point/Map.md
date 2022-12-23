# Map

## 概念

* 一种键值对容器.每一对中的第一个值称之为关键字(key)，每个关键字只能在map中出现一次；第二个称之为该关键字的对应值。
* 能自动排序
## 操作

* 声明：#include <map>
* 插入
```c++
#include <iostream>
#include <map>

int main()
{
    std::map<char, int> mymap;

    //使用[ ]进行单个插入
    mymap[2015] = "Tom";

    // 插入单个值
    mymap.insert(pair<string,int>("apple",2));
    mymap.insert(std::pair<char, int>('a', 100));
    mymap.insert(std::pair<char, int>('z', 200));

    //返回插入位置以及是否插入成功
    std::pair<std::map<char, int>::iterator, bool> ret;
    ret = mymap.insert(std::pair<char, int>('z', 500));
    if (ret.second == false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
    }

    //指定位置插入
    std::map<char, int>::iterator it = mymap.begin();
    mymap.insert(it, std::pair<char, int>('b', 300));  //效率更高
    mymap.insert(it, std::pair<char, int>('c', 400));  //效率非最高

    //范围多值插入
    std::map<char, int> anothermap;
    anothermap.insert(mymap.begin(), mymap.find('c'));

    // 列表形式插入
    anothermap.insert({ { 'd', 100 }, {'e', 200} });

    return 0;
}
```
* * 统计某个字符出现多少次
```c++ 
    map<ll, int>mp;//容量是ll类，对应的值是int类
    mp.clear();//清空
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;//a[i]是键值
    }
    mp.size()//有几种
    mp[a[n]]//a[n]有几个
```
* 取值:Map中元素取值主要有at和[ ]两种操作，at会作下标检查，而[]不会。
```c++
map<int, string> ID_Name;

//ID_Name中没有关键字2016，使用[]取值会导致插入
//因此，下面语句不会报错，但打印结果为空
cout<<ID_Name[2016].c_str()<<endl;

//使用at会进行关键字检查，因此下面语句会报错,因为没有
ID_Name.at(2016) = "Bob";
```
* 容量查询
* * mp.empty() 是否空
* * mp.size() 数量对
* * count() 返回指定元素出现的次数(因为key值不会重复，所以只能是1 or 0)
* it = mp.begin(); 迭代器
* 删除
```c++
// 删除迭代器指向位置的键值对，并返回一个指向下一元素的迭代器
iterator mp.erase( iterator pos )//里面是迭代器

// 删除一定范围内的元素，并返回一个指向下一元素的迭代器
iterator mp.erase( const_iterator first, const_iterator last );

// 根据Key来进行删除， 返回删除的元素数量，在map里结果非0即1
size_t mp.erase( const key_type& key );

// 清空map，清空后的size为0
void mp.clear();
```
* 交换：void swap( map& other );就是两个map的内容互换 
* 顺序比较:key_compare key_comp() const;
```c++
// 比较两个关键字在map中位置的先后
map<char,int> mymap;
map<char,int>::key_compare mycomp = mymap.key_comp();
mymap['a']=100;
mymap['b']=200;
mycomp('a', 'b');  // a排在b前面，因此返回结果为true
```
* 查找
```c++
// 关键字查询，找到则返回指向该关键字的迭代器，否则返回指向end的迭代器
// 根据map的类型，返回的迭代器为 iterator 或者 const_iterator
iterator find (const key_type& k);
const_iterator find (const key_type& k) const;

//sample
std::map<char,int> mymap;
std::map<char,int>::iterator it;//迭代器

mymap['a']=50;
mymap['b']=100;
mymap['c']=150;
mymap['d']=200;

it = mymap.find('b');
if (it != mymap.end())
    mymap.erase (it); // b被成功删除
```