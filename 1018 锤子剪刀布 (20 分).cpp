// 1018 锤子剪刀布 (20 分)
// 大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
// FigCJB.jpg
// 现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

// 输入格式：
// 输入第 1 行给出正整数 N（≤105），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

// 输出格式：
// 输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。

// 输入样例：
// 10
// C J
// J B
// C B
// B B
// B C
// C C
// C B
// J B
// B C
// J J
// 输出样例：
// 5 3 2
// 2 3 5
// B B

#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

// 判断a,b的输赢，和返回0，a赢了b返回1，输了返回-1
int judge(char a, char b)
{
    int out;
    if (a == b)
    {
        return 0;
    }
    // 下面a和b就不可能再相等
    if (a == 'B')
    {
        if (b == 'C')
        {
            out = 1;
        }
        else
        {
            out = -1;
        }
    }
    else if (a == 'C')
    {
        if (b == 'J')
        {
            out = 1;
        }
        else
        {
            out = -1;
        }
    }
    else
    {
        if (b == 'B')
        {
            out = 1;
        }
        else
        {
            out = -1;
        }
    }
    return out;
}

int main()
{
    int N;
    cin >> N;
    char jia, yi;
    int wins = 0, ties = 0, loses = 0; // 甲胜、平、负次数
    map<char, int> A, B;               // 甲、乙获胜次数最多的手势
    for (int i = 0; i < N; ++i)
    {
        cin >> jia >> yi;
        int judgement = judge(jia, yi);
        if (judgement == 0)
        {
            ++ties;
        }
        else if (judgement == 1)
        {
            ++wins;
            ++A[jia]; // 甲胜的手势
        }
        else
        {
            ++loses;
            ++B[yi]; // 甲输时，乙赢了的手势
        }
    }
   
    cout << wins << " " << ties << " " << loses << endl;
    cout << loses << " " << ties << " " << wins << endl;
    // 先找到map中的最大值，然后找到第一个键，由于map本身就是字典序
    // 所以第一个键对应的就是字典序最小的
    int maxA=max(max(A['C'],A['J']),A['B']);
    int maxB=max(max(B['C'],B['J']),B['B']);
    for(auto x:A)
    {
        if(x.second==maxA)
        {
            cout<<x.first<<" ";
            // 找到的第一个，就是字母序最小的解
            break;
        }
    }
    for(auto x:B)
    {
        if(x.second==maxB)
        {
            cout<<x.first<<endl;
            break;
        }
    }
    
    return 0;
}