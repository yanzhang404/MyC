#include <iostream>
using namespace std;

int coin[5]={1,5,10,20,50};


int main(){
    int n;
    cin>>n;
    int change = 100-n;
    int res = 0;
    for(int i = 4;i>=0;i--){
        while(change >=coin[i]){
        change-=coin[i];
        res++;
        }
    }
    cout<<res<<endl;
    return 0;
}