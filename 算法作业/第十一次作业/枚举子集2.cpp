#include <iostream>


using namespace std;
const int N = 110;
int nums[N];
int vis[N];
int n;
void dfs(int u){
    if(u == n){
        for(int i = 0; i < n;i++)
            if(vis[i] == 1)
                cout<<nums[i]<<" ";
        cout<<endl;
        return;
    }
    vis[u] = 1;
    dfs(u+1);
    vis[u] = 0;
    dfs(u+1);
}
int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    dfs(0);

    return 0;
}