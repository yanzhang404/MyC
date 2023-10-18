#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//无向图判断是否是树，那我直接用临接矩阵好了
const int N = 50;
vector< vector<int> > G(N, vector<int>(N,0));
int m; // 边数
bool isTree(int n){ //传入点数
    int sum = 0;
    for(int i = 0; i < n + 1; i ++){
        for(int j = 0; j < n + 1; j++){
            if(G[i][j] == 1) sum++;
        }
    }
    int deg = sum - n;  //所有点的度 16 - 8 = 8
    if(deg ==  m * 2 && m == n - 1) return true;
    else return false;
}
int main(){
    cin>>m;
    int n = 0;
    for(int i = 0; i < m; i++){
        int a,b;
        cin>>a>>b;
        G[a][a] = 1;
        G[b][b] = 1;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    for(int i = 0; i < N; i++){
        if(G[i][i] == 1)    n++;
    }

    for(int i = 0; i< n + 1; i++){
        for(int j = 0; j < n + 1; j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"num:"<<n<<endl;
    if(isTree(n))   cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}