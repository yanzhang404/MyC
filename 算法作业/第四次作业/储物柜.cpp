#include <iostream>
#include <vector>

using namespace std;


const int N = 10e7+10;
int n, q;
int i,j,k; //柜子、格子、物品编号
int op; //操作
vector<int> res;
vector<int>:: iterator it;
int main(){
    cin>>n>>q;
    vector< vector<int> > cab(n+1);
    while(q--){
        cin>>op;
        if(op == 1){
            cin>>i>>j>>k;
            if(cab[i].size()<j) cab[i].resize(j+10,0); //如果格子不够，可动态增加数组
            cab[i][j] = k;
        }
        else if (op == 2){
            cin>>i>>j;
            res.push_back(cab[i][j]);
        }
    }
    for(it = res.begin(); it!=res.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}