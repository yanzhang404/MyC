#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m; //点和边
int h[N], e[N], ne[N], idx;
int d[N];   //  代表到第i个点的路径
bool st[N]; // 是否搜索过

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;

}

int res = 0;
int sum = 1;
int dfs(int u){ //通过深搜求最长路径
    st[u] = true;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]) {
            sum++;
            dfs(j);
            sum--;
        }
        res = max(res, sum);
    }
    return res;
}

int main(){
    cin>>n;
    m = n - 1;
    memset(h,-1,sizeof h);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >>a>>b;
        add(a,b);
    }
    int d = dfs(1);
    int res = (m - d) * 2 + d;
    cout<<res<<endl;
    return 0;
}