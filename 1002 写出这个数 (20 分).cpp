// 1002 写出这个数 (20 分)
// 读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

// 输入格式：
// 每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100


// 输出格式：
// 在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

// 输入样例：
// 1234567890987654321123456789
// 输出样例：
// yi san wu


#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 10^100 beyond the range of long long,wo can only use string
int main()
{
    string s;
    cin >> s;
    int sum = 0;
    for(auto i:s)
    {
        sum += i-'0';
    }

    vector<string> v={"ling", "yi", "er", "san","si","wu","liu","qi","ba","jiu"};
    string string_sum = to_string(sum);
    unsigned j = 0;
    // the size() and length() in string are the same thing
    while(j<string_sum.size()-1)
    {
        cout << v[string_sum[j]-'0'] << " ";
        j++;
    }
    cout << v[string_sum[j]- '0'] << endl;

    return 0;
}
