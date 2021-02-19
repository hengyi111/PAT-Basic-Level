// 1008 数组元素循环右移问题 (20 分)
// 一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（≥0）个位置，即将A中的数据由
// （A0​​A1⋯A​N−1）变换为（AN−M⋯AN−1A0A1⋯AN−M−1）
// （最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？
// 输入格式:
// 每个输入包含一个测试用例，第1行输入N（1≤N≤100）和M（≥0）；第2行输入N个整数，之间用空格分隔。

// 输出格式:
// 在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

// 输入样例:
// 6 2
// 1 2 3 4 5 6
// 输出样例:
// 5 6 1 2 3 4

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 直接输出的方法，用c的数组或者用vector<int>效果一样
int main1()
{
    int N, M;
    cin >> N >> M;
    vector<int> v(N);

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cin >> *it;
    }
    M = M % N;
    for (int i = N - M; i < N; i++)
    {
        cout << v[i] << " ";
    }

    for (int i = 0; i < N - M - 1; i++)
    {
        cout << v[i] << " ";
    }
    cout << v[N - M - 1];
    return 0;
}

// 用算法reverse三次来实现，在python中可以直接用deque
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> v(N);

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cin >> *it;
    }
    M = M % N;
    // 先反转前半部分，再反转后半部分，然后整体反转
    reverse(v.begin(), v.begin() + N - M);
    reverse(v.end() - M, v.end());
    reverse(v.begin(), v.end());
    for (unsigned i = 0; i < v.size(); ++i)
    {
        i == v.size() - 1 ? cout << v[i] : cout << v[i] << " ";
    }

    return 0;
}


/* python版本
n, m = map(int, input().split())
a = list((map(int, input().split())))
m = m % n
for _ in range(m):
    a.insert(0,a.pop())
for i in range(n-1):
        print(a[i], end=' ')
print(a[n-1])


*/