// 1064 朋友数 (20 分)
// 如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。例如 123 和 51 就是朋友数，因为 1+2+3 = 5+1 = 6，而 6 就是它们的朋友证号。给定一些整数，要求你统计一下它们中有多少个不同的朋友证号。

// 输入格式：
// 输入第一行给出正整数 N。随后一行给出 N 个正整数，数字间以空格分隔。题目保证所有数字小于 10
// ​4。

// 输出格式：
// 首先第一行输出给定数字中不同的朋友证号的个数；随后一行按递增顺序输出这些朋友证号，数字间隔一个空格，且行末不得有多余空格。

// 输入样例：
// 8
// 123 899 51 998 27 33 36 12
// 输出样例：
// 4
// 3 6 9 26

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    set<int> si;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        int out = 0;
        for (auto i : s)
        {
            out += i - '0';
        }
        si.insert(out);
    }
    cout << si.size() << endl;
    // set中就是按照字典序排列的
    // 输出元素方法1
    bool flag = true;
    for (const auto i : si)
    {
        if (flag)
        {
            cout << i;
            flag = false;
        }
        else
        {
            cout << " " << i;
        }
    }
    // 第二种方法
    // set<int>::iterator it = si.begin();
    // cout << *it++;
    // while(it!=si.end())
    // {
    //     cout << " " << *it++;
    // }

    return 0;
}