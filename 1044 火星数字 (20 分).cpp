// 1044 火星数字 (20 分)
// 火星人是以 13 进制计数的：

// 地球人的 0 被火星人称为 tret。
// 地球人数字 1 到 12 的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
// 火星人将进位以后的 12 个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
// 例如地球人的数字 29 翻译成火星文就是 hel mar；而火星文 elo nov 对应地球数字 115。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

// 输入格式：
// 输入第一行给出一个正整数 N（<100），随后 N 行，每行给出一个 [0, 169) 区间内的数字 —— 或者是地球文，或者是火星文。

// 输出格式：
// 对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

// 输入样例：
// 4
// 29
// 5
// elo nov
// tam
// 输出样例：
// hel mar
// may
// 115
// 13

#include <iostream>
#include <string>

using namespace std;

const string low[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const string high[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int MarsToEarth(string s)
{
    int h = 0;
    int l = 0;
    string hs;
    string ls;
    if (s.size() > 4)
    {
        hs = s.substr(0, 3);
        ls = s.substr(4, 3);
    }
    else
    {
        // 如果只有一个字符串，
        // 则要么是在高位中，要么是在低位中，不可能同时存在
        hs = s;
        ls = s;
    }
    for (int i = 0; i < 13; ++i)
    {
        if (high[i] == hs)
        {
            h = i * 13;
            break;
        }
    }

    for (int i = 0; i < 13; ++i)
    {
        if (low[i] == ls) // 如果不相等，则默认值就是0
        {
            l = i;
            break;
        }
    }
    return h + l;
}

string EarthToMars(int i)
{
    string h = high[i / 13];
    string l = low[i % 13];

    if (h != "")
    {
        if (l == "tret")
        {
            l = ""; // 如果低位为0，则不需要在低位输出tret
        }
        else
        {
            h += " "; // 不然加上一个空格，用来后续加上低位
        }
    }
    return h + l;
}

int main()
{
    int n;
    scanf("%d\n", &n);
    string s;
    for (int i = 0; i < n; ++i)
    {
        getline(cin, s);
        if (isdigit(s[0]))
        {
            cout << EarthToMars(stoi(s)) << endl;
        }
        else
        {
            cout << MarsToEarth(s) << endl;
        }
    }

    return 0;
}
