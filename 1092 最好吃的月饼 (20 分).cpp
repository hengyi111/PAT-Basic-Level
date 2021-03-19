// 1092 最好吃的月饼 (20 分)
// 月饼是久负盛名的中国传统糕点之一，自唐朝以来，已经发展出几百品种。

// mk.jpg

// 若想评比出一种“最好吃”的月饼，那势必在吃货界引发一场腥风血雨…… 在这里我们用数字说话，给出全国各地各种月饼的销量，要求你从中找出销量冠军，认定为最好吃的月饼。

// 输入格式：
// 输入首先给出两个正整数 N（≤1000）和 M（≤100），分别为月饼的种类数（于是默认月饼种类从 1 到 N 编号）和参与统计的城市数量。

// 接下来 M 行，每行给出 N 个非负整数（均不超过 1 百万），其中第 i 个整数为第 i 种月饼的销量（块）。数字间以空格分隔。

// 输出格式：
// 在第一行中输出最大销量，第二行输出销量最大的月饼的种类编号。如果冠军不唯一，则按编号递增顺序输出并列冠军。数字间以 1 个空格分隔，行首尾不得有多余空格。

// 输入样例：
// 5 3
// 1001 992 0 233 6
// 8 0 2018 0 2008
// 36 18 0 1024 4
// 输出样例：
// 2018
// 3 5

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vi(n);
    for (int i = 0; i < m; i++) // 城市
    {
        for (int j = 0; j < n; j++) // 每种月饼个数
        {
            int temp;
            cin >> temp;
            vi[j] += temp;
        }
    }
    // max_element 返回vector中的最大值的迭代器
    int out_max = *max_element(vi.begin(), vi.end());
    vector<int> index;
    for (int i = 0; i < n; i++)
    {
        if (vi[i] == out_max)
        {
            index.push_back(i);
        }
    }
    cout << out_max << endl;
    // 因为编号从1开始，所以在这里加1
    cout << index[0] + 1;
    for (int i = 1; i < index.size(); ++i)
    {
        cout << " " << index[i] + 1;
    }

    return 0;
}