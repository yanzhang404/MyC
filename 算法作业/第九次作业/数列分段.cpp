#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+10;


int n,m;
int q[N];
int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>q[i];
    }
    int sum = 0,res = 0;
    for(int i = 0; i < n; i++){
        if(sum +q[i] <= m){
            sum+=q[i];
        }
        else{
            res = res + 1;
            sum = q[i];
        }
    }
    res++;
    cout<<res<<endl;
    return 0;
}