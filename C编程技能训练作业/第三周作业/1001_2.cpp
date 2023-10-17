#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
const int M = 10010;

int n = 0, m;
int h[N], e[M],ne[M], idx;
bool st[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u){
    st[u] = true;
    n++;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j])  dfs(j);  
    }
}

bool IsTree(){
    dfs(1);
    if(n - 1 == m)  return true;
    else    return false;
}

int main(){
    cin>>m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        add(a,b);
    }
    if(IsTree()) cout<<"YES"<<endl;
    else    cout<<"NO"<<endl;
    return 0;
}