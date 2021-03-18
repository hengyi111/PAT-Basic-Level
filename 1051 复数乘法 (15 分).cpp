// 1051 复数乘法 (15 分)
// 复数可以写成 (A+Bi) 的常规形式，其中 A 是实部，B 是虚部，i 是虚数单位，满足 i
// ​2=−1；也可以写成极坐标下的指数形式 (R×e(Pi))，其中 R 是复数模，P 是辐角，i 是虚数单位，其等价于三角形式 R(cos(P)+isin(P))。

// 现给定两个复数的 R 和 P，要求输出两数乘积的常规形式。

// 输入格式：
// 输入在一行中依次给出两个复数的 R1, P1, R2, P2，数字间以空格分隔。

// 输出格式：
// 在一行中按照 A+Bi 的格式输出两数乘积的常规形式，实部和虚部均保留 2 位小数。注意：如果 B 是负数，则应该写成 A-|B|i 的形式。

// 输入样例：
// 2.3 3.5 5.2 0.4
// 输出样例：
// -8.68-8.23i

#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    double r1, p1, r2, p2;
    scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
    double a = r1 * r2 * cos(p1 + p2);
    double b = r1 * r2 * sin(p1 + p2);
    // 要求保留2位小数，小于0.01则直接置为0
    if (fabs(a) < 0.01)
    {
        a = 0;
    }
    if (fabs(b) < 0.01)
    {
        b = 0;
    }

    if (b < 0)
    {
        printf("%.2lf%.2lfi\n", a, b);
    }
    else
    {
        printf("%.2lf+%.2lfi\n", a, b);
    }

    return 0;
}