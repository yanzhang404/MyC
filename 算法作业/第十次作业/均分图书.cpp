#include <iostream>

using namespace std;

const int N = 110;
int n;
int a[N];
int main(){
    cin>>n;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    int avr = sum/n;
    int cnt = 0;
    for(int i = 1;i <=n ;i++){
        if(a[i]!= avr){
            a[i+1] += a[i] - avr;
            a[i] = avr;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}