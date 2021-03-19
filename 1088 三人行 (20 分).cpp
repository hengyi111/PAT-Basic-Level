// 1088 三人行 (20 分)
// 子曰：“三人行，必有我师焉。择其善者而从之，其不善者而改之。”

// 本题给定甲、乙、丙三个人的能力值关系为：甲的能力值确定是 2 位正整数；把甲的能力值的 2 个数字调换位置就是乙的能力值；甲乙两人能力差是丙的能力值的 X 倍；乙的能力值是丙的 Y 倍。请你指出谁比你强应“从之”，谁比你弱应“改之”。

// 输入格式：
// 输入在一行中给出三个数，依次为：M（你自己的能力值）、X 和 Y。三个数字均为不超过 1000 的正整数。

// 输出格式：
// 在一行中首先输出甲的能力值，随后依次输出甲、乙、丙三人与你的关系：如果其比你强，输出 Cong；平等则输出 Ping；比你弱则输出 Gai。其间以 1 个空格分隔，行首尾不得有多余空格。

// 注意：如果解不唯一，则以甲的最大解为准进行判断；如果解不存在，则输出 No Solution。

// 输入样例 1：
// 48 3 7
// 输出样例 1：
// 48 Ping Cong Gai
// 输入样例 2：
// 48 11 6
// 输出样例 2：
// No Solution

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

//用来比较并输出string的函数
string compare(double m, double w)
{
    return w == m ? " Ping" : w > m ? " Cong"
                                    : " Gai";
}

int main()
{
    // 我自己的能力m，为整数
    int m, x, y;
    cin >> m >> x >> y;
    //甲乙的能力也为整数，甲为2位，乙可能为1位或2位
    int a, b;
    double c; // 丙可以为小数
    // 如果解不唯一，则以甲的最大解为准进行判断,所以递减i
    bool flag = false;
    for (int i = 99; i > 10; i--)
    {
        int bb = i % 10 * 10 + i / 10;      // 乙的能力
        double cc1 = abs(i - bb) * 1.0 / x; // 丙的能力不能为负
        double cc2 = bb * 1.0 / y;
        if (fabs(cc1 - cc2) <= 1e-5) //如果满足条件
        {
            a = i, b = bb, c = cc1;
            flag = true; // 表明找到了解
            break;
        }
    }
    // 如果没有找到解
    if (!flag)
    {
        cout << "No Solution" << endl;
    }
    else
    {
        cout << a << compare(m, a) << compare(m, b) << compare(m, c) << endl;
    }

    return 0;
}
