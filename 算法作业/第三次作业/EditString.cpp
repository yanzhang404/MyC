#include <iostream>

using namespace std;

const int N = 1010;

char a[N], b[N];
int n,m;
int dp[N][N];

int main(){
    cin>>n>> (a+1)>>m>> (b+1);
    //先更新[0][i]和[i][0]
    for(int i = 0; i <=m; i++) dp[0][i] = i;
    for(int i = 0; i <=n; i++) dp[i][0] = i;

    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=m; j++){
            dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
            if(a[i] == b[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}