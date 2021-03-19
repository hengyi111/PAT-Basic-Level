// 1091 N-自守数 (15 分)
// 如果某个数 K 的平方乘以 N 以后，结果的末尾几位数等于 K，那么就称这个数为“N-自守数”。例如 3×922=25392，而 25392 的末尾两位正好是 92，所以 92 是一个 3-自守数。

// 本题就请你编写程序判断一个给定的数字是否关于某个 N 是 N-自守数。

// 输入格式：
// 输入在第一行中给出正整数 M（≤20），随后一行给出 M 个待检测的、不超过 1000 的正整数。

// 输出格式：
// 对每个需要检测的数字，如果它是 N-自守数就在一行中输出最小的 N 和 NK2的值，以一个空格隔开；否则输出 No。注意题目保证 N<10。

// 输入样例：
// 3
// 92 5 233
// 输出样例：
// 3 25392
// 1 25
// No

#include <iostream>
#include <string>
#include<cmath>
using namespace std;

int main()
{
    int m;
    cin >> m;

    for (int i = 0; i < m; ++i)
    {
        int temp;
        cin >> temp;
        int len = (to_string(temp)).length();
        bool flag = false;
        for (int n = 0; n < 10; n++) // 输出最小的n
        {
            int mi = n * temp * temp;
            int last = mi % (int)(pow(10,len));
            if (last == temp)
            {
                cout << n << " " << mi << endl;
                flag = true;
                break;
            }
        }
        if (!flag) // 如果没有找到
        {
            cout << "No" << endl;
        }
    }

    return 0;
}