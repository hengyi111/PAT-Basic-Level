// 1081 检查密码 (15 分)
// 本题要求你帮助某网站的用户注册模块写一个密码合法性检查的小功能。该网站要求用户设置的密码必须由不少于6个字符组成，并且只能有英文字母、数字和小数点 .，还必须既有字母也有数字。

// 输入格式：
// 输入第一行给出一个正整数 N（≤ 100），随后 N 行，每行给出一个用户设置的密码，为不超过 80 个字符的非空字符串，以回车结束。

// 输出格式：
// 对每个用户的密码，在一行中输出系统反馈信息，分以下5种：

// 如果密码合法，输出Your password is wan mei.；
// 如果密码太短，不论合法与否，都输出Your password is tai duan le.；
// 如果密码长度合法，但存在不合法字符，则输出Your password is tai luan le.；
// 如果密码长度合法，但只有字母没有数字，则输出Your password needs shu zi.；
// 如果密码长度合法，但只有数字没有字母，则输出Your password needs zi mu.。
// 输入样例：
// 5
// 123s
// zheshi.wodepw
// 1234.5678
// WanMei23333
// pass*word.6
// 输出样例：
// Your password is tai duan le.
// Your password needs shu zi.
// Your password needs zi mu.
// Your password is wan mei.
// Your password is tai luan le.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar(); // 吸收换行符
    for (int i = 0; i < n; ++i)
    {
        string s;
        getline(cin, s);
        if (s.length() < 6)
        {
            cout << "Your password is tai duan le." << endl;
        }
        else
        {
            bool has_digit = false;
            bool has_alpha = false;
            bool is_ok = true;
            for (int i = 0; i < s.length(); ++i)
            {
                if (isdigit(s[i]))
                {
                    has_digit = true;
                }
                else if (isalpha(s[i]))
                {
                    has_alpha = true;
                }
                else if (s[i] == '.')
                {
                    continue;
                }
                else // 如果出现了其他不合法的字符
                {
                    is_ok = false;
                    cout << "Your password is tai luan le." << endl;
                    break;
                }
            }
            if (is_ok)
            {
                if (!has_alpha)
                {

                    cout << "Your password needs zi mu." << endl;
                }
                else if (!has_digit)
                {
                    cout << "Your password needs shu zi." << endl;
                }
                else
                {
                    cout << "Your password is wan mei." << endl;
                }
            }
        }
    }

    return 0;
}
