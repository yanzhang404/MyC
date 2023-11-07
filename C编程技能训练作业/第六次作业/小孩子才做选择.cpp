#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> candies(n);
    int max_candies = 0;
    for (int i = 0; i < n; i++) {
        cin >> candies[i];
        max_candies = max(max_candies,candies[i]);
    }
    // 使用哈希表记录每个糖果堆的数量
    unordered_map<int, long long> candyCounts;
    for (int i = 0; i < n; i++) {
        candyCounts[candies[i]] += candies[i];
    }
    vector<int> value(max_candies + 1,0);

    // 动态规划过程
    for(auto it = candyCounts.begin(); it!=candyCounts.end();it++){
        value[it->first] = it->second;
    }
    vector<int> dp(max_candies+1);
    //dp[i]代表前i个能获得的最大价值
    dp[0] = value[0];//前0个价值最大是0
    for(int i = 1; i <= max_candies; i++){
        dp[i] = max(dp[i-1],dp[i-2]+ value[i]);
    }
    cout<<dp[max_candies]<<endl;
    //打家劫舍
    return 0;
}
