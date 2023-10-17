#include <iostream>
#include <limits.h>
using namespace std;

const int N = 10010;
int nums[N];
int dp[N];//dp[i]代表到第i个数字时到最大和


int main(){
    int n;
    cin>>n;
    int res = INT_MIN;
    for(int i = 0; i <= n; i++){
        cin>>nums[i];
    }
    dp[0] = nums[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(nums[i], dp[i-1] + nums[i]);
    }
    for(int i = 0 ; i < n; i++){
        res = max(res, dp[i]);
    }
    cout<<res<<endl;
    return 0;
}