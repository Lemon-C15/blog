/*
5
1 2 3 4 5
2
3 2 1 5 4 YES
3 4 2 1 5 YES
*/
3输入，读取数组直到3，因为接下来不是2out就是4out，所以先退一位看看是不是2，如果不是先进一位空位再读4，再比较，再退一位，以此类推；


```C++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int main()
{
    int n, i, t;
    int s[10010];
    int a[10010];
    scanf("%d", &n);//length
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int p, q;
    int m;
    scanf("%d", &m);//test number
    while(m--)
    {
        p = 0;
        q = -1;
        for(i = 0; i < n; i++)//
        {                    //依次比较
            scanf("%d", &t);//
            while(q == -1 || s[q] != t)//t=a[p]
            {
                if(p >= n) break;
                s[++q] = a[p++];//cover
                //p++;
            }
            //如果有后面的符合顺序，则逆序使q--(双向，退一位)
            if(t == s[q])
                q--;
        }
        if(q == -1)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
```