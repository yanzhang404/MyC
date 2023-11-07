//增大数量级
//采用二进制优化方法

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;


const int N = 2010;
int n, m;
int f[N];
struct good{
    int v,w;
};



int main(){
    vector<good> goods;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        int v,w,s;
        cin>>v>>w>>s;
        for(int k = 1; k <=s; k = k*2){
            s-=k;
            good temp;
            temp.v = k*v;
            temp.w = k*w;
            goods.push_back(temp);
        }
        good temp;
            temp.v = s*v;
            temp.w = s*w;
        goods.push_back(temp);
    }
    //现在变成了0-1背包问题
    for(int i = 0; i < goods.size(); i++){
        for(int j = m;j>=goods[i].v;j--){
            f[j] = max(f[j], f[j-goods[i].v]+goods[i].w);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
