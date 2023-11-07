#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;


const int N = 310;

int n;

int w[N];
int dp[N][N]; // 代表第i个到第j个合并完的代价
int sum[N];
int main(){

    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>w[i];
        sum[i] = sum[i-1] + w[i];
    }
    for(int len = 2; len <= n; len++) {
    for(int i = 1; i <= n-len+1; i++) {
        int j = i + len - 1;
        dp[i][j] = INT_MAX;
        for(int k = i; k < j; k++) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
