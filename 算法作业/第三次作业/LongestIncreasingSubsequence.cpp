#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int> nums, int n){
    vector<int> dp(n,1);
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j =0; j<i; j++){
            if(nums[j] < nums[i]) dp[i] = max(dp[i],dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    return res;
}


int main(){

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    int res = lengthOfLIS(nums, n);
    cout<<res<<endl;
    return 0;
}