#include <iostream>
#include <set>
#include <string>
using namespace std;


const int N = 5;

int q[N][N];
int dx[4] = {0,1,0,-1}, dy[4] ={1,0,-1,0};
string path;
set<string> res;

void dfs(int u, int x, int y){
    if( u == 6) {
    res.insert(path);
    return;
    }
    path += q[x][y] + '0';
    for(int i = 0; i < 4; i++){
        int a = x+dx[i], b = y + dy[i];
        if(a >=0 && a < N && b >= 0 && b < N){
            dfs(u+1, a, b);
        }
    }
    path = path.substr(0,path.size() - 1);
}


int main(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>q[i][j];
        }
    }   
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dfs(0,i,j);
        }
    }
    int ant = 0;
    for(auto i : res){
        ant++;
    }
    cout<<ant<<endl;
    return 0;
}

