// 1043 输出PATest (20 分)
// 给定一个长度不超过 104的、仅由英文字母构成的字符串。请将字符重新调整顺序，按 PATestPATest.... 这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按 PATest 的顺序打印，直到所有字符都被输出。

// 输入格式：
// 输入在一行中给出一个长度不超过 104的、仅由英文字母构成的非空字符串。

// 输出格式：
// 在一行中按题目要求输出排序后的字符串。题目保证输出非空。

// 输入样例：
// redlesPayBestPATTopTeePHPereatitAPPT
// 输出样例：
// PATestPATestPTetPTePePee

#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main()
{
    char ch;
    vector<int> nums(6); // PATest
    while ((ch = cin.get()) != '\n')
    {
        switch (ch)
        {
        case 'P':
            nums[0]++;
            break;
        case 'A':
            nums[1]++;
            break;
        case 'T':
            nums[2]++;
            break;
        case 'e':
            nums[3]++;
            break;
        case 's':
            nums[4]++;
            break;
        case 't':
            nums[5]++;
            break;
        default:
            break;
        }
    }
    string s = "PATest";
    int count = accumulate(nums.begin(), nums.end(), 0);
    int j = 0;
    while (count)
    {
        if (nums[j] != 0)
        {
            cout << s[j];
            nums[j]--;
            // 只有不为空有真正输出时，count才递减
            count--;
        }
        //每次移动索引到下一位
        j++;
        j %= 6;
    }

    return 0;
}
