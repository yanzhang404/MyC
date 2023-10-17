#include <iostream>
using namespace std;

const int N = 110;
int coin[N];
int dp[N]; // dp[i]代表偷第i家时的最大金额

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>coin[i];
    }
    dp[0] = coin[0];
    dp[1] = max(coin[0],coin[1]);
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-1],dp[i-2] + coin[i]);
    }
    cout<<dp[n-1]<<endl;
    return 0;
}