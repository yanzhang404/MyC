#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n; // 列数
    vector<vector<int> > nums(2, vector<int>(n));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }
    vector<vector<int> > dp(2, vector<int>(n));
    // 初始化第一列
    dp[0][0] = nums[0][0];
    dp[1][0] = nums[1][0];
  
  // 动态规划计算最大和
    for(int j = 1; j < n; j++) {
        for(int i = 0; i < 2; i++) {
            dp[i][j] = max(dp[1 - i][j-1] + nums[i][j], dp[i][j-1]);
        }
    }
    // 最终结果为最后一列两行中的较大值
    int res = max(dp[0][n-1], dp[1][n-1]);
    cout << res << endl;
    return 0;
}