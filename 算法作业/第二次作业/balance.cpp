#include <iostream>
using namespace std;

const int N = 20;
int n, res;
int w[N];
int v[N];

bool check(){
    int sum = 0;
    for(int i = 1; i <= n; i++ ){
        sum += w[i]*v[i];
    }
    return sum == 0;
}
void f(int step){
    if(step > n){
        if(check()){
            res++;
        } 
        return;
    }

    for(int i = -1; i <= 1; i++){
        v[step] = i;
        f(step + 1);
    }
}

int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>w[i];
    }
    f(1);
    cout<<res<<endl;
}
