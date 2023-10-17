#include <iostream>
using namespace std;


bool isPerfectNumber(int n){
    int sum = 0;
    for(int i = 1; i<=n/2; i++){
        if( n % i == 0) sum+=i;
    }
    if(sum == n)    return true;
    else    return false;
}

int main(){

    int n;
    cin>>n;
    if(isPerfectNumber(n))  cout<<"YES"<<endl;
    else    cout<<"NO"<<endl;
    return 0;
}