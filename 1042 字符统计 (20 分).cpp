// 1042 字符统计 (20 分)
// 请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

// 输入格式：
// 输入在一行中给出一个长度不超过 1000 的字符串。字符串由 ASCII 码表中任意可见字符及空格组成，至少包含 1 个英文字母，以回车结束（回车不算在内）。

// 输出格式：
// 在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

// 输入样例：
// This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
// 输出样例：
// e 7

#include<string>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

// 1使用vector
int main1()
{
    string s;
    getline(cin, s);
    vector<int> num(26);
    for (int i = 0; i < (int)s.length();++i)
    {
        if(isalpha(s[i]))  // 如果是字母
        {
            // 转成小写，减去’a',得到索引，然后递增
            num[tolower(s[i]) - 'a']++;  
        }
    }
    int max_count = 0;
    int max_index = 0;
    for (int i = 0; i < 26;i++)
    {
        if(num[i]>max_count)
        {
            max_count = num[i];
            max_index = i;
        }

    }
    cout << char('a' + max_index) << " " << max_count << endl;

    return 0;
}

// 使用map
int main()
{
    char ch;
    map<char, int> m;
    while((ch = cin.get())!='\n')
    {
        if(isalpha(ch))
        {
            m[tolower(ch)]++;
        }
    }
    // map本身是按照字典序排列键的
    int max_count = -1;
    for(auto &x:m)
    {
        if(x.second>max_count)
        {
            ch = x.first;
            max_count = x.second;
        }
    }
    cout << ch << " " << max_count << endl;

    return 0;
}