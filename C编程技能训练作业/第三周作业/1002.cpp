#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


const int N = 110;
const int M = 10010;
int h[N], e[M], ne[M], idx;
int n, m;  //点数， 边数
int s, t; // 起点，终点
bool st[N];

void add(int a, int b){  // 添加边
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;  
}


void dfs(int u){  //从u深度优先遍历图
    st[u] = true;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]) dfs(j);
    }
}


int main(){
    cin>>n>>m>>s>>t;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        add(a,b);
    }
    dfs(s);  //从起始点开始深度优先遍历图
    if(st[t])   cout<<1<<endl;//如果 t被遍历到了，则说明存在路径，否则不存在
    else    cout<<0<<endl;
    return 0;

}