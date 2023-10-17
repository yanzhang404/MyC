#include <iostream>
using namespace std;

const int N = 1010;
int num[N][N]; //存储数字三角形
int dp[N][N];  //dp[i][j]代表从下往上到第[i][j]的最大值

int main(){
    int r;
    cin>>r;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j<=i; j++){
            cin>>num[i][j];
        }
    }

    for(int i = r; i>=1; i--){
        for(int j = 1; j<=i; j++){
            dp[i][j] = max(dp[i+1][j]+num[i][j], dp[i+1][j+1]+num[i][j]);
        }
    }
    cout<<dp[1][1]<<endl;
    return 0;

}