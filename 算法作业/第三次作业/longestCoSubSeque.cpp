#include <iostream>

using namespace std;

const int N = 1010;

char a[N],b[N]; // 存字符

int dp[N][N];
//dp[i][j]代表a中a1-ai和b1-bj中的最大公共子序列的长度

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= m; i++){
        cin>>b[i];
    }

    for(int i = 1; i <=n; i++){
        for( int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    cout<<dp[n][m]<<endl;
}