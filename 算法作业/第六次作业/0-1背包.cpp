#include <iostream>

using namespace std;

const int N = 1010;
int n,m;//n件物品，背包容量为m
int f[N]; //容量为j的背包的最大价值
int main(){
    cin>>n>>m;
    for(int i = 1; i <=n; i++){
        int v,w;
        cin>>v>>w;
        for(int j = m; j >=v; j--){
            f[j] = max(f[j],f[j-v]+w);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
