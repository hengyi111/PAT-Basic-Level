// 1024 科学计数法 (20 分)
// 科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，即数字的整数部分只有 1 位，小数部分至少有 1 位，该数字及其指数部分的正负号即使对正数也必定明确给出。

// 现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。

// 输入格式：
// 每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。

// 输出格式：
// 对每个测试用例，在一行中按普通数字表示法输出 A，并保证所有有效位都被保留，包括末尾的 0。

// 输入样例 1：
// +1.23400E-03
// 输出样例 1：
// 0.00123400
// 输入样例 2：
// -1.2E+10
// 输出样例 2：
// -12000000000

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    // 最前面的＋不需要输出，只需要输出-号
    if (s[0] == '-')
    {
        cout << "-";
    }
    int pos = s.find('E');
    // 数字部分，用字符串，因为有小数点
    string numString = s.substr(1, pos - 1);
    //指数部分，可以用int，因为没有小数点
    int exp = stoi(s.substr(pos + 2, s.length() - pos - 1));

    if (exp == 0) // 如果没有指数部分
    {
        cout << numString;
    }
    else
    {
        // 如果指数为－，则需要先输出很多0
        if (s[pos + 1] == '-')
        {
            cout << "0.";
            while (exp > 1) // 第一个已经输出
            {
                cout << '0';
                --exp;
            }
            // 位于第二位的小数点不能再输出
            cout << numString[0] << numString.substr(2, numString.length() - 2);
        }
        // 如果指数为+，则小数点的位置会有移动或者完全消失
        else
        {
            // 小数点前的一位反正会输出的
            cout << numString[0];
            int i = 2;                                // 从小数点后的一位开始输出
            while (exp > 0 && i < numString.length()) // 输出位数不超过数字部分本身长度
            {
                cout << numString[i];
                ++i;
                exp--; // 用指数控制需要输出的位数
            }
            // 如果指数部分先用完了
            if (i < numString.length())
            {
                cout << "." << numString.substr(i, numString.length() - i);
            }
            else // 如果是numString长度先用完了
            {
                while (exp > 0)
                {
                    cout << 0;
                    --exp;
                }
            }
        }
    }

    return 0;
}