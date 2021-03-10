// 1029 旧键盘 (20 分)
// 旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

// 输入格式：
// 输入在 2 行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过 80 个字符的串，由字母 A-Z（包括大、小写）、数字 0-9、以及下划线 _（代表空格）组成。题目保证 2 个字符串均非空。

// 输出格式：
// 按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有 1 个坏键。

// 输入样例：
// 7_This_is_a_test
// _hs_s_a_es
// 输出样例：
// 7TI

#include<iostream>
#include<string>

using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string out = "";
    int index = 0, index_max = s2.length();
    for (auto it = s1.begin(); it!= s1.end();++it)
    {
        if(*it==s2[index]&&index!=index_max)  // 该键没有坏
        {
            if(index!=index_max)
            {
                ++index;
            }
        }
        else  // 到这里的就是坏键
        {
            if(islower(*it))
            {
                // 小写转大写
                *it = *it + 'A' - 'a';      
            }
            // 如果当前的坏键不在要输出的out中，则添加进去
            if(out.find(*it)==string::npos)
            {
                out += *it;
            }
        }
        
    }
    cout << out << endl;

    return 0;
}
