#include <iostream>
#include <cmath>
using namespace std;

bool PrimeJudge(int n){
    for(int i =2; i<=sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
    
}

int main(){
    int n;
    cin>>n;
    for(int i =1; i<=n/2;i++){
        if(n % i == 0)  cout<<i<<endl;
    }
    return 0;
}