#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;
int n,k;
char s[N][N];
bool col[N];
int res = 0;

void dfs(int u){
    if(k == 0){
        res++;
        return;
    }
    if(u == n){
        return;
    }
    for(int i = 0; i < n; i++){
        if(!col[i] && s[u][i] == '#'){
            col[i] = true;
            k--;
            dfs(u+1);
            col[i] = false;
            k++;
        }
    }
    dfs(u+1);
}


int main(){
    cin>>n>>k;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            cin>>s[i][j];
        }
    }
    dfs(0);
    cout<<res<<endl;
    //现在我有一个棋盘了，下面对每一行来dfs
    return 0;
}