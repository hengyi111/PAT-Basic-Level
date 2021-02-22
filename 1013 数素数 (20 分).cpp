// 1013 数素数 (20 分)
// 令 Pi表示第 i 个素数。现任给两个正整数 M≤N≤104，请输出 PM
// 到 PN的所有素数。

// 输入格式：
// 输入在一行中给出 M 和 N，其间以空格分隔。

// 输出格式：
// 输出从 P​M到 PN的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

// 输入样例：
// 5 27
// 输出样例：
// 11 13 17 19 23 29 31 37 41 43
// 47 53 59 61 67 71 73 79 83 89
// 97 101 103

#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int number = 0; // 第几个编号
    int start = 2;
    int count = 0; // 统计可以输出的数字
    while (number < n)
    {
        if (isPrime(start))
        {
            ++number;
            if (number >= m) // 第m个以及之后
            {
                ++count;
                cout << start;
                if (number == n)  // 遇到最后一个数字，没有空格和换行
                {
                    ;
                }
                else
                {
                    if (count % 10 == 0)
                    {
                        cout << endl;  // 换行
                    }
                    else
                    {
                        cout << " ";  // 空格
                    }
                }
            }
        }
        ++start;
    }

    return 0;
}