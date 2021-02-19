// 1010 一元多项式求导 (25 分)
// 设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为nxn−1。）

// 输入格式:
// 以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。

// 输出格式:
// 以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0。

// 输入样例:
// 3 4 -5 2 6 1 -2 0
// 输出样例:
// 12 3 -10 1 6 0

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int n;
    // 读入
    while (cin >> n)
    {
        v.push_back(n);
        if (getchar() == '\n')
        {
            break;
        }
    }
    auto length = v.size();
    if (v[1] == 0)  // 只需要第二个数字为1，第一个数字可以为任意值
    {
        cout << "0 0" << endl;
    }
    else
    {
        cout << v[0] * v[1] << " " << v[1] - 1;
        for (decltype(length) j = 2; j < length; j += 2)
        {
            if (v[j + 1] == 0)
            {
                break;
            }
            cout << " " << v[j] * v[j + 1] << " " << v[j + 1] - 1;
        }
        cout << endl;
    }

    return 0;
}