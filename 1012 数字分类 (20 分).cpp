// 1012 数字分类 (20 分)
// 给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：

// A1 = 能被 5 整除的数字中所有偶数的和；
// A2= 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n1−n2+n3−n4⋯；
// A3= 被 5 除后余 2 的数字的个数；
// A4= 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
// A5= 被 5 除后余 4 的数字中最大数字。
// 输入格式：
// 每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。

// 输出格式：
// 对给定的 N 个正整数，按题目要求计算 A1~A5
// 并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

// 若其中某一类数字不存在，则在相应位置输出 N。

// 输入样例 1：
// 13 1 2 3 4 5 6 7 8 9 10 20 16 18
// 输出样例 1：
// 30 11 2 9.7 9
// 输入样例 2：
// 8 1 2 4 5 6 7 9 16
// 输出样例 2：
// N 11 2 N 9

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// 是否存在都使用标志位来标注，记得要初始化
// 控制输出，printf比cout要好用
int main()
{
    int N;
    cin >> N;
    int A1 = 0, A2 = 0, A3 = 0, A4 = 0, A5 = 0;
    int temp;
    int sign = 1;
    double count_A4 = 0;
    int exist_A1 = 0, exist_A2 = 0, exist_A3 = 0, exist_A4 = 0, exist_A5 = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        switch (temp % 5)
        {
        case 0:
            if (temp % 2 == 0)
            {
                A1 += temp;
                exist_A1 = 1;
            }
            break;

        case 1:
            A2 += sign * temp;
            sign = -sign;
            exist_A2 = 1;
            break;
        case 2:
            ++A3;
            exist_A3 = 1;
            break;
        case 3:
            A4 += temp;
            ++count_A4;
            exist_A4 = 1;
            break;
        case 4:
            if (temp > A5)
            {
                A5 = temp;
                exist_A5 = 1;
            }
            break;

        default:
            break;
        }
    }

    // 开始输出A1
    if (exist_A1 == 0)
    {
        cout << "N";
    }
    else
    {
        cout << A1;
    }
    cout << " ";
    //A2
    if (exist_A2 == 0)
    {
        cout << "N";
    }
    else
    {
        cout << A2;
    }
    cout << " ";
    //A3
    if (exist_A3 == 0)
    {
        cout << "N";
    }
    else
    {
        cout << A3;
    }
    cout << " ";

    //A4
    if (exist_A4 == 0)
    {
        cout << "N";
    }
    else
    {
        double average = A4 / count_A4;
        printf("%.1lf", average);
    }
    cout << " ";

    //A5
    if (exist_A5 == 0)
    {
        cout << "N";
    }
    else
    {
        cout << A5;
    }
}