// 1060 爱丁顿数 (25 分)**
// 英国天文学家爱丁顿很喜欢骑车。据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数” E ，即满足有 E 天骑车超过 E 英里的最大整数 E。据说爱丁顿自己的 E 等于87。

// 现给定某人 N 天的骑车距离，请你算出对应的爱丁顿数 E（≤N）。

// 输入格式：
// 输入第一行给出一个正整数 N (≤105)，即连续骑车的天数；第二行给出 N 个非负整数，代表每天的骑车距离。

// 输出格式：
// 在一行中给出 N 天的爱丁顿数。

// 输入样例：
// 10
// 6 7 6 9 3 10 8 2 7 8
// 输出样例：
// 6

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 用了goto，并不是很好
int main1()
{
    int n;
    cin >> n;
    vector<int> vi(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vi[i];
    }
    // 从大到小排序
    sort(vi.rbegin(), vi.rend());
    int e = n;
    for (; e >= 0; e--)
    {
        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            if (vi[i] > e)
            {
                count++;
            }
            if (count == e)
            {
                goto label;
            }
        }
    }
label:
    if (e < 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << e << endl;
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    // 从小到大排序
    sort(a.begin(), a.end());

    int i = n - 1;
    int count = 0;
    int e;
    // 这个循环不是很懂？？
    do
    {
        e = a[i] - 1;
        count++;
        i--;
    } while (i >= 0 && count < e);

    // 到这里，count等于e了
    if (e < 0)
    {
        e = 0;
    }
    cout << e << endl;

    return 0;
}