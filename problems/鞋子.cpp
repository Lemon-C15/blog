//https://codeforces.com/contest/1691/problem/B
//思路：必须有偶数对
#include <bits/stdc++.h>

using namespace std;

#define ll long long
typedef vector<ll> vll;//long long类型的向量
#define io                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main()
{
    io;//加速
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        vll s(n), p(n);// 向量
        for (ll i = 0; i < n; ++i)
            cin >> s[i];

        ll l = 0, r = 0;
        bool ans = true;//判断
        for (ll i = 0; i < n; ++i)
            p[i] = i + 1;//标号

        while (r < n)
        {
            while (r < n - 1 and s[r] == s[r + 1]) // get range [l,r] with equal values
                ++r;
            if (l == r)//only one
                ans = false;//0//the mark
            else
                rotate(p.begin() + l, p.begin() + r, p.begin() + r + 1); // rotate right in range [l,r]
                //首位至尾函数rotate
                //begin为向量中第几个
            l = r + 1;
            ++r;
        }
        if (ans)
        {
            for (auto &x : p)//遍历每一个值//取值
                cout << x << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
