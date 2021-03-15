// 1038 统计同成绩学生 (20 分)
// 本题要求读入 N 名学生的成绩，将获得某一给定分数的学生人数输出。

// 输入格式：
// 输入在第 1 行给出不超过 105的正整数 N，即学生总人数。随后一行给出 N 名学生的百分制整数成绩，中间以空格分隔。最后一行给出要查询的分数个数 K（不超过 N 的正整数），随后是 K 个分数，中间以空格分隔。

// 输出格式：
// 在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。

// 输入样例：
// 10
// 60 75 90 55 75 99 82 90 75 50
// 3 75 90 88
// 输出样例：
// 3 2 0

#include <iostream>
#include <vector>
#include<cstdio>

using namespace std;

// 如果学生总人数很多的话，感觉使用vector索引的0-100来指示分数更快
int main1()
{
    // 提高cin、cout效率
    // 用下面这两句话，是可以显著提高cin和cout的效率的。
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int temp;
    vector<int> v(101, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        v[temp]++;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> temp;
        if (i < k - 1)
        {
            cout << v[temp] << " ";
        }
        else
        {
            cout << v[temp] << endl;
        }
    }

    return 0;
}

// 使用printf速度也很快
int main()
{
    int n;
    cin >> n;
    int temp;
    vector<int> v(101, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        v[temp]++;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> temp;
        if (i < k - 1)
        {
            printf("%d ", v[temp]);
        }
        else
        {
            printf("%d\n", v[temp]);
        }
    }

    return 0;
}