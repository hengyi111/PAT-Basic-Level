// 1037 在霍格沃茨找零钱 (20 分)
// 如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱 P 和他实付的钱 A，你的任务是写一个程序来计算他应该被找的零钱。

// 输入格式：
// 输入在 1 行中分别给出 P 和 A，格式为 Galleon.Sickle.Knut，其间用 1 个空格分隔。这里 Galleon 是 [0, 10
// ​7] 区间内的整数，Sickle 是 [0, 17) 区间内的整数，Knut 是 [0, 29) 区间内的整数。

// 输出格式：
// 在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

// 输入样例 1：
// 10.16.27 14.1.28
// 输出样例 1：
// 3.2.1
// 输入样例 2：
// 14.1.28 10.16.27
// 输出样例 2：
// -3.2.1

#include <cstdio>

using namespace std;

int main()
{
    long long g1, g2, s1, s2, k1, k2;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &g1, &s1, &k1, &g2, &s2, &k2);
    long long out = (17 * 29 * g2 + 29 * s2 + k2) - (17 * 29 * g1 + 29 * s1 + k1);
    if (out < 0)
    {
        printf("-");
        out = -out;
    }
    long long g, s, k;
    k = out % 29;
    out /= 29; // 全部用s的个数
    s = out % 17;
    g = out / 17;
    printf("%lld.%lld.%lld", g, s, k);

    return 0;
}