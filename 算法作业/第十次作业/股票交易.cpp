#include <iostream>

using namespace std;


const int N = 1010;
int prices[N];
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>prices[i];
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        if(prices[i] < prices[i+1]) res = res + prices[i+1] - prices[i];
    }
    cout<<res<<endl;
    return 0;

}