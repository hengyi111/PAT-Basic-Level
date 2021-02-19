// 1009 说反话 (20 分)
// 给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

// 输入格式：
// 测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。

// 输出格式：
// 每个测试用例的输出占一行，输出倒序后的句子。

// 输入样例：
// Hello World Here I Come
// 输出样例：
// Come I Here World Hello

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    vector<string> v;
    string s;
    while(cin>>s)
    {
        v.push_back(s);
        // 如果碰到了换行符，就打破循环
        if(getchar()=='\n')
        {
            break;
        }
    }
    // 1索引逆序输出
    // cout << v[v.size() - 1];
    // for (int i = v.size() - 2; i >= 0;--i)
    // {
    //     cout << " " << v[i];
    // }

   //2迭代器逆序输出
    for (auto it = v.cend()-1; it >= v.cbegin();--it)
    {
        if(it==v.cend()-1)  // 需要-1，因为不能到尾后迭代器
        {
            cout << *it;
        }
        else
        {
            cout << " " << *it;
        }
        
    }

        return 0;
}