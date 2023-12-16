#include <iostream>
#include <vector>
using namespace std;


const int  N = 110;
int n;
int q[N];
int vis[N];
vector<int> path;

void dfs(int u){
    if( u == n){
        for(int i = 0; i < n; i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(vis[i] != 1){
            path.push_back(q[i]);
            vis[i] = 1;
            dfs(u+1);
            vis[i] = 0;
            path.pop_back();
        }
    }
}

int main(){
    cin>> n;
    for(int i = 0; i < n; i++){
        cin>>q[i];
    }
    dfs(0);
    return 0;
}