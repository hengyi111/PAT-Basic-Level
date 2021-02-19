// 1003 我要通过！ (20 分)**
// “答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

// 得到“答案正确”的条件是：

// 字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
// 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
// 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
// 现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

// 输入格式：
// 每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。

// 输出格式：
// 每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。

// 输入样例：
// 8
// PAT
// PAAT
// AAPATAA
// AAPAATAAAA
// xPATx
// PT
// Whatever
// APAAATAA
// 输出样例：
// YES
// YES
// YES
// YES
// NO
// NO
// NO
// NO

#include <iostream>
#include <string>

using namespace std;

//条件1就是最基本的。然后条件2和3应该综合起来考虑，P和T中间一个A
//则P前一个x，T后一个x，如果P和T中间再加一个A,则T的后面需要再
//加一个P前面的字符串
// 我们知道aPbTc中a b c 段都只能包含“A”，其长度分别为len(a)、len(b)、
// len(c)，则其关系满足len(a)*len(b) = len(c)。这完美的契合了条件二
// 与条件三，xPATx 就是当len(b) = 1，（a=x,c=x,b=A）的情况，
// 在此基础上演化到条件三B中每增加一个A，c中相应增加一段“a”以上
// 的乘法关系式成立。

// 限制条件
// A必须大于等于1，PT必须等于1，P前的A乘PT之间的A等于T之后的A
int main()
{
    unsigned n;
    cin >> n;
    string s;
    for (unsigned i = 0; i < n; ++i)
    {
        unsigned p = 0, a = 0, t = 0;//用于记录P、A、T个数
        int ppos = -1, tpos = -1;//记录P和A的位置
        cin >> s;
        // 统计字符串中每个字符的数量
        for (unsigned j = 0; j < s.length(); ++j)
        {
            switch (s[j])
            {
            case 'A':
                ++a;
                break;
            case 'P':
                ++p;
                ppos = j;
                break;
            case 'T':
                ++t;
                tpos = j;
                break;
            default:
                break;
            }
        }
        // 限制条件,不能有其他字符
        // A必须大于等于1，PT必须等于1，P前的A乘PT之间的A等于T之后的A
        if((p+a+t==s.length())&&a>=1&&p==1&&t==1&&(ppos*(tpos-ppos-1)==(int)s.length()-tpos-1))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }

    return 0;
}