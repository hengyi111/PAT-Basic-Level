// 1048 数字加密 (20 分)**
// 本题要求实现一种数字加密方法。首先固定一个加密用正整数 A，对任一正整数 B，将其每 1 位数字与 A 的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对 13 取余——这里用 J 代表 10、Q 代表 11、K 代表 12；对偶数位，用 B 的数字减去 A 的数字，若结果为负数，则再加 10。这里令个位为第 1 位。

// 输入格式：
// 输入在一行中依次给出 A 和 B，均为不超过 100 位的正整数，其间以空格分隔。

// 输出格式：
// 在一行中输出加密后的结果。

// 输入样例：
// 1234567 368782971
// 输出样例：
// 3695Q8118

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int main()
{
    const char s[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    string a, b;
    cin >> a >> b;
    int len_a = a.size();
    int len_b = b.size();
    int max_len = max(len_b, len_a);
    // 在较短的字符串前面补0
    a = string(max_len - len_a, '0') + a;
    b = string(max_len - len_b, '0') + b;
    string out(max_len, '0'); // 初始化输出的字符串为长串0
    int pos = 1;              // 奇数位开始，对应索引为最后一位
    while (pos <= max_len)
    {
        int index = max_len - pos;
        if (pos % 2 == 1)
        {
            out[index] = s[(a[index] - '0' + b[index] - '0') % 13];
        }
        else // 相减不可能为JQK
        {
            // 正数+10没有影响，负数就是要+10
            out[index] = (b[index] - a[index] + 10) % 10 + '0';
        }
        ++pos;
    }

    cout << out << endl;

    return 0;
}