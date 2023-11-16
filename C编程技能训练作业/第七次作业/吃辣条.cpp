/*
Alice 参加了学院近期举办的吃辣条大赛, 桌子上摆放了若干根辣条, 每根辣条的长度不等,
 要求只能按从左到右长度严格递增的顺序吃, 每位参赛选手有一次机会扔掉其中的一根辣条(也可以不扔).
给出从左到右排列的每根辣条的长度, 请问 Alice 最多可以吃到多少根辣条
输入包含两行, 第一行为一个正整数n∈[2,200000], 表示辣条的总数.
第二行为n 个正整数l1,⋯,ln, 用空格分隔, 表示每根辣条的长度 ∈[1,10^9].
测试样例:
6
2 3 8 4 5 7
结果为5，可以扔掉第3根
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=2e5+5;
int n,a[maxn],l[maxn],r[maxn];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)//最初每个数都是一个长度为1的递增序列，所以初始化为1
        l[i]=1;
    for(int i=1;i<=n;i++)
        r[i]=1;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int maxlen=1;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]<a[i+1]){
            r[i]=r[i+1]+1;//（如：1 2 3 5 2 4，r[i]依次为4 3 2 1 2 1）
        }
        maxlen=max(maxlen,r[i]);
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1]){
            l[i]=l[i-1]+1;//（如：1 2 3 5 2 4，l[i]依次为1 2 3 4 1 2）
        }
        maxlen=max(maxlen,l[i]);
    }
    for(int i=1;i<=n-2;i++)
    {
        if(a[i]<a[i+2]){
            maxlen=max(maxlen,l[i]+r[i+2]);
        }
    }
    cout<<maxlen<<endl;
    return 0;
}