// 1034 有理数四则运算 (20 分)
// 本题要求编写程序，计算 2 个有理数的和、差、积、商。

// 输入格式：
// 输入在一行中按照 a1/b1 a2/b2 的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为 0。

// 输出格式：
// 分别在 4 行中按照 有理数1 运算符 有理数2 = 结果 的格式顺序输出 2 个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式 k a/b，其中 k 是整数部分，a/b 是最简分数部分；若为负数，则须加括号；若除法分母为 0，则输出 Inf。题目保证正确的输出中没有超过整型范围的整数。

// 输入样例 1：
// 2/3 -4/2
// 输出样例 1：
// 2/3 + (-2) = (-1 1/3)
// 2/3 - (-2) = 2 2/3
// 2/3 * (-2) = (-1 1/3)
// 2/3 / (-2) = (-1/3)
// 输入样例 2：
// 5/3 0/6
// 输出样例 2：
// 1 2/3 + 0 = 1 2/3
// 1 2/3 - 0 = 1 2/3
// 1 2/3 * 0 = 0
// 1 2/3 / 0 = Inf

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

// 化简分式需要知道最大公约数GCD
long long GCD(long long a, long long b)
{
    long long r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 将该数转换为有理数的最简形式，传入的就是数的分子和分母
// 并且需要考虑负数和外面加括号的形式
string RNString(long long a, long long b)
{
    string str = "";
    if (b < 0) // 保证负号位于分子上而不是分母上
    {
        b = -b;
        a = -a;
    }
    // 先用最大公约数化到最简
    long long g = GCD(abs(a), b);
    a /= g;
    b /= g;

    // 如果分子大于分母，需要化成带分数
    if (abs(a) >= b)
    {
        str += to_string(a / b);
        if (a % b != 0)
        {
            str += " ";
            str += to_string((abs(a)) % b);
            str += "/";
            str += to_string(b);
        }
    }
    // 如果本身就是真分数了
    else
    {
        str += to_string(a);
        if (a != 0) // 如果分子不为0,则说明还有分母部分
        {
            str += "/";
            str += to_string(b);
        }
    }
    // 如果是负数，还需要再外面加上一层括号
    if (a < 0)
    {
        str = "(" + str;
        str += ")";
    }
    return str;
}

int main()
{
    string s[2];
    // a用来保存分子，b用来保存分母 a1/b1,a2/b2
    long long a[2], b[2];
    for (int i = 0; i < 2; ++i)
    {
        scanf("%lld/%lld", &a[i], &b[i]);
        // 得到的是一个带分数的string
        s[i] = RNString(a[i], b[i]);
    }

    // 加法,通分然后相加，得到对应的分子分母
    long long ra = a[0] * b[1] + a[1] * b[0];
    long long rb = b[0] * b[1];
    cout << s[0] << " + " << s[1] << " = " << RNString(ra, rb) << endl;
    // 减法
    ra = a[0] * b[1] - a[1] * b[0];
    rb = b[0] * b[1];
    cout << s[0] << " - " << s[1] << " = " << RNString(ra, rb) << endl;

    //乘法
    ra = a[0] * a[1];
    rb = b[0] * b[1];
    cout << s[0] << " * " << s[1] << " = " << RNString(ra, rb) << endl;

    //除法
    ra = a[0] * b[1];
    rb = b[0] * a[1];
    cout << s[0] << " / " << s[1] << " = ";
    if (rb == 0)  // 如果分母为0，则为inf
    {
        cout << "Inf" << endl;
    }
    else
    {
        cout << RNString(ra, rb) << endl;
    }

    return 0;
}