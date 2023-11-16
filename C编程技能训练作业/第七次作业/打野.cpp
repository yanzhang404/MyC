/*
题目：
在 Dota 游戏中, 英雄通过击败野外的怪物(简称野怪)可以获取一定量的金币, 但是在此过程中也会损失一定量的生命值.
现在一位名为奈文摩尔的英雄希望通过击败野怪来获取金币, 假设他的初始生命值为 
R, 在保证英雄不被野怪击败(即 R≥0)的情况下, 求该英雄最多可以获取多少金币.输入包含三行, 第一行为两个正整数 ,N,R∈[1,1000] 分别表示野怪的数量以及奈文摩尔的初始生命值.
第二行包含N 个正整数, 表示击败每个野怪可以得到的金币,
第三行包含 N 个正整数, 表示击败每个野怪需要消耗的生命值.
*/

#include <iostream>

using namespace std;

const int N = 1010;
int n,r;
int coin[N]; // 击败野怪获得的金币
int hp[N];//击败野怪消耗的生命值
int dp[N]; //dp[i][j]代表前i个野怪使用生命j可以获得的最多金币，优化为dp[j]

//生命值就是空间，金币就是价值，0-1背包问题

int main(){
    cin>>n>>r;
    for(int i = 0; i < n; i++){
        cin>>coin[i];
    }

    for(int i = 0; i < n; i++){
        cin>>hp[i];
    }
    for(int i = 1; i <= n;i++){
        for(int j = r; j >= hp[i-1]; j--){
            dp[j] = dp[j];
            if(j >= hp[i-1]){
                dp[j] = max(dp[j], dp[j-hp[i-1]] + coin[i-1]);
            }
        }
    }
    cout<<dp[r]<<endl;
    return 0;
}
