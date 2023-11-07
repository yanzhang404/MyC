#include <iostream>
#include <algorithm>

using namespace std;


const int N = 1010;
int n;
    int prices[N];
    int dp[N][2];//代表第i天持有或者卖出
int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>prices[i];
    }
    dp[0][0] = 0;
    dp[0][1] = -1e6;//第0天持有的利润
    for(int i = 1; i <= n; i ++){
        //第i天不持有的最大利润是前一天未持有的最大利润或者是前一天持有今天卖出
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        //第i天持有的最大利润是前一天持有的最大利润或者前一天未持有今天买入
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
    }
    cout<<dp[n][0]<<endl;
    return 0;
}