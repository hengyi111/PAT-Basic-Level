// 1007 素数对猜想 (20 分)
// 让我们定义dn为：dn=pn+1−pn，其中pi是第i个素数。显然有d1=1，且对于n>1有d
// ​n是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
// 现给定任意正整数N(<105)，请计算不超过N的满足猜想的素数对的个数。

// 输入格式:
// 输入在一行给出正整数N。

// 输出格式:s
// 在一行中输出不超过N的满足猜想的素数对的个数。

// 输入样例:s
// 20
// 输出样例:
// 4

#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int count = 0; // if N<5,the count is 0
    int N;
    cin >> N;
    // 方法1
    // int pre = 3;
    // for (int i = 5; i <= N; ++i)
    // {
    //     if (isPrime(i))
    //     {
    //         if (i - pre == 2)
    //         {
    //             ++count;
    //         }
    //         pre = i;
    //     }
    // }
    //方法2
    //这里的条件也可以改为当前是质数且+2后依旧是质数
    for (int i = 3; i <= N - 2; i++)
    {
        if (isPrime(i) && isPrime(i + 2))
        {
            ++count;
        }
    }
    cout << count << endl;

    return 0;
}