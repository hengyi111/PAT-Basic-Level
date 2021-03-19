// 1086 就不告诉你 (15 分)
// 做作业的时候，邻座的小盆友问你：“五乘以七等于多少？”你应该不失礼貌地围笑着告诉他：“五十三。”本题就要求你，对任何一对给定的正整数，倒着输出它们的乘积。

// 53.jpg

// 输入格式：
// 输入在第一行给出两个不超过 1000 的正整数 A 和 B，其间以空格分隔。

// 输出格式：
// 在一行中倒着输出 A 和 B 的乘积。

// 输入样例：
// 5 7
// 输出样例：
// 53

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int out = a * b;
    string s = to_string(out);
    reverse(s.begin(), s.end());
    // 要注意，前面的0不输出，0*0的0也不需要输出
    bool flag = true;
    for (string::size_type i = 0; i < s.size(); ++i)
    {
        if (s[i] == '0' && flag)
        {
            ;
        }
        else
        {
            cout << s[i];
            flag = false;
        }
    }

    return 0;
}
