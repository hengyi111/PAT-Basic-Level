// 1005 继续(3n+1)猜想 (25 分)
// 卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。

// 当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对 n=3 进行验证的时候，我们需要计算 3、5、8、4、2、1，则当我们对 n=5、8、4、2 进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这 4 个数已经在验证3的时候遇到过了，我们称 5、8、4、2 是被 3“覆盖”的数。我们称一个数列中的某个数 n 为“关键数”，如果 n 不能被数列中的其他数字所覆盖。

// 现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

// 输入格式：
// 每个测试输入包含 1 个测试用例，第 1 行给出一个正整数 K (<100)，第 2 行给出 K 个互不相同的待验证的正整数 n (1<n≤100)的值，数字间用空格隔开。

// 输出格式：
// 每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用 1 个空格隔开，但一行中最后一个数字后没有空格。

// 输入样例：
// 6
// 3 5 6 7 8 11
// 输出样例：
// 7 6


//迭代器中简单的删除会使得程序出错，最好用erase删除，如it1 = ll.erase(it1);
#include <iostream>
#include <list> // 双向链表，支持随机访问和删除remove

using namespace std;
bool cmp(int a1, int a2) // for sort(),from big to smalls
{
    return a1 > a2;
}

int main()
{
    int n;
    cin >> n;
    list<int> l(n);
    // read data in
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        cin >> (*it);
    }
    list<int> ll = l;  // 得到副本，也只删除副本中的元素

    // caculate Callatz guess
    for (auto it = l.cbegin(); it != l.cend(); ++it)
    {
        int temp = *it;
        while (temp != 1)
        {
            temp = (temp % 2 == 0) ? (temp / 2) : ((3 * temp + 1) / 2);
            for (list<int>::iterator it1 = ll.begin(); it1 != ll.end(); ++it1)
            {
                if (temp == *it1)
                {
                    ll.remove(temp);// 出现了的元素，如果有存在的，就在ll中删除
                    break;  // 这一句必须存在，一旦出现删除就调出迭代器循环
                    // 另一种删除方法
                    // it1 = ll.erase(it1); // 或者使用这种删除方法
                }
            }
        }
    }
    ll.sort(cmp);  // from big to smalls
    for (auto it = ll.cbegin(); it != ll.cend(); ++it)
    {
        if (it != ll.cbegin())
        {
            cout << " ";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}