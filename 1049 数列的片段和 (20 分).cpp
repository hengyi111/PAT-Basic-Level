// 1049 数列的片段和 (20 分)
// 给定一个正数数列，我们可以从中截取任意的连续的几个数，称为片段。例如，给定数列 { 0.1, 0.2, 0.3, 0.4 }，我们有 (0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4) 这 10 个片段。

// 给定正整数数列，求出全部片段包含的所有的数之和。如本例中 10 个片段总和是 0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0。

// 输入格式：
// 输入第一行给出一个不超过 105的正整数 N，表示数列中数的个数，第二行给出 N 个不超过 1.0 的正数，是数列中的数，其间以空格分隔。

// 输出格式：
// 在一行中输出该序列所有片段包含的数之和，精确到小数点后 2 位。

// 输入样例：
// 4
// 0.1 0.2 0.3 0.4
// 输出样例：
// 5.00

#include <cstdio>
#include <iostream>

using namespace std;
//求和公式S(n) = n*a1 + 2(n-1)*a2 + 3(n-2)*a3 + ... + n*an;
int main()
{
    long n;  //这里需要使用long
    cin >> n;
    // 这两个需要使用 long double，不然会溢出
    long double a;
    long double out = 0.0;  

    for (long i = 0; i < n; ++i)
    {
        cin >> a;
        out += (i + 1) * (n - i) * a;
    }
    printf("%.2llf", out);

    return 0;
}