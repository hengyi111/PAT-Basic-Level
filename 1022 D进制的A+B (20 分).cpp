// 1022 D进制的A+B (20 分)
// 输入两个非负 10 进制整数 A 和 B (≤230−1)，输出 A+B 的 D (1<D≤10)进制数。

// 输入格式：
// 输入在一行中依次给出 3 个整数 A、B 和 D。

// 输出格式：
// 输出 A+B 的 D 进制数。

// 输入样例：
// 123 456 8
// 输出样例：
// 1103

#include <iostream>
#include <vector>

// int占用4字节[-2^31~2^31-1]
using namespace std;
int main()
{
    int A, B, D;
    cin >> A >> B >> D;
    int C;
    C = A + B;
    if (C == 0)
    {
        cout << 0 << endl;
    }
    int r;
    vector<int> vr;
    while (C)
    {
        r = C % D; //余数
        C = C / D;
        vr.push_back(r);
    }
    for (auto it = vr.rbegin(); it != vr.rend(); ++it)
    {
        cout << *it;
    }

    return 0;
}