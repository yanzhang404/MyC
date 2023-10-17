#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int res = 0;
    while(n){
        n = n&(n-1);
        res++;
    }
    cout<<res<<endl;
    return 0;
}