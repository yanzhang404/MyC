#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 10010;
int nums[2][N];
int dp[2][N][2];
int main() {
    int n; // 列数
    cin >> n;
    for(int i = 0; i < n; i++){
        cin>>nums[0][i];
    }
    for(int i = 0; i < n; i++){
        cin>>nums[1][i];
    }
    dp[0][0][1] = nums[0][0];
    dp[1][0][1] = nums[1][0];
    dp[0][0][0] = nums[1][0];
    dp[1][0][0] = nums[0][0];
    for(int j = 1; j < n; j++){
        dp[0][j][1] = max(dp[0][j-1][0]+nums[0][j],dp[0][j-1][1]);
        dp[1][j][1] = max(dp[1][j-1][0]+nums[1][j],dp[1][j-1][1]);
        dp[0][j][0] = max(dp[0][j-1][1],dp[1][j][1]);
        dp[1][j][0] = max(dp[1][j-1][1],dp[0][j][1]);
    }
    int res = max(dp[0][n-1][1],dp[0][n-1][0]);
    res = max(res,dp[1][n-1][1]);
    res = max(res,dp[1][n-1][0]);
    cout<<res<<endl;
    return 0;
/*
dp[i][j][1]代表选了nums[i][j]这个数的最大值，dp[i][j][0]代表没选这个数的最大值
dp[0][j][1] = max(dp[0][j-1][0]+nums[0][j],dp[0][j-1][1]);
dp[0][j][0] = max(dp[0][j-1][1]+nums[1][j][1]);
dp[1][j][1] = max(dp[1][j-1][0]+nums[1][j],dp[1][j-1][1]);
dp[1][j][0] = max(dp[1][j-1][1]+nums[0][j][1]);
*/

}
