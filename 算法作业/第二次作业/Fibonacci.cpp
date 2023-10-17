#include <iostream>
using namespace std;


int n;
const int N = 51;
long long s[N];
long long f(int n){
    s[0] = 0;
    s[1] = 1;
    for(int i =2; i<=n; i++){
        s[i] = s[i-1] + s[i-2];
    }
    return s[n];
}


int main(){
    cin>>n;
    cout<<f(n)<<endl;
    return 0;
}