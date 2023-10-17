#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long sum = 0;
    long long first = 1, second = 1;
    for(int i = 2; i <= n;i++){
        sum = first + second;
        first = second;
        second = sum;
    }
    if(n == 1){
        cout<<1<<endl;
    }
    else
        cout<<sum<<endl;
    return 0;

}

