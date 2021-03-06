// 1016 部分A+B (15 分)
// 正整数 A 的“DA（为 1 位整数）部分”定义为由 A 中所有 DA组成的新整数 P
// ​A。例如：给定 A=3862767，DA=6，则 A 的“6 部分”PA是 66，因为 A 中有 2 个 6。
// 现给定 A、DA、B、DB，请编写程序计算 P​A+PB 。

// 输入格式：
// 输入在一行中依次给出 A、D​A、B、DB，中间以空格分隔，其中 0<A,B<1010。

// 输出格式：
// 在一行中输出 PA+PB的值。

// 输入样例 1：
// 3862767 6 13530293 3
// 输出样例 1：
// 399
// 输入样例 2：
// 3862767 1 13530293 8
// 输出样例 2：
// 0

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// 这个写法比较好
int main()
{
    int part(string & s, char d); // 返回的直接是数字
    string A, B;
    char DA, DB;
    cin >> A >> DA >> B >> DB;
    cout << part(A, DA) + part(B, DB) << endl;
    return 0;
}
int part(string &s, char d)
{
    string str;
    for (auto ss : s)
    {
        if (ss == d)
        {
            str += ss;
        }
    }
    return str.size() ? stoi(str) : 0;
}

// 这个写法不太好，将判断拆成函数更好，count也可以用单纯的数字实现
int main1()
{
    string A, B;
    char DA, DB; //直接读入char
    cin >> A >> DA >> B >> DB;
    string::size_type ca, cb;

    ca = count(A.begin(), A.end(), DA);
    cb = count(B.begin(), B.end(), DB);
    string out1, out2;
    // 要考虑字符串是否为0的情况
    if (ca == 0)
    {
        out1 = '0';
    }
    else
    {
        out1 = string(ca, DA);
    }
    if (cb == 0)
    {
        out2 = '0';
    }
    else
    {
        out2 = string(cb, DB);
    }

    long long out = stoll(out1) + stoll(out2);
    cout << out << endl;

    return 0;
}