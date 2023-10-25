#include <iostream>
#include <algorithm>

using namespace std;

//使用前缀和来写
const int N = 10e4+10;

int n;
int nums[N];
int sum[N];
int k; 
int cnt;
int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>nums[i];
        sum[i] = sum[i-1] + nums[i];  //保存所有的和
    }
    cin>>k;
    for(int i = 0; i <= n; i++){ //用sum[j] - sum[i] 表示一个区间内数的和
        for(int j = i + 1; j <=n; j++){ 
            if(sum[j]-sum[i] == k){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}