#include <iostream>

using namespace std;

const int N = 22;
int n;
int q[N][N];
int temp;
int res;
int A[N];

void dfs(int u){
    if(u == n){
        // for(int i = 0; i < n; i++){
        //     cout<<A[i]<<" ";
        // }
        // cout<<endl;
        for(int i = 0; i < n; i++){
            if(A[i]){
                for(int j = 0; j < n; j++){
                    if(!A[j])   temp +=q[i][j];
                }
            }
        }
        cout<<"temp="<<temp<<endl;
        res = max(res, temp);
        temp = 0;
        return;
    }
    A[u] = 1;
    dfs(u + 1);
    A[u] = 0;
    dfs(u + 1);

}
int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>q[i][j];
        }
    }
    dfs(0);
    cout<<res<<endl;
    return 0;
}