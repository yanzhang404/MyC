#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> light(n+1,1); //1代表开着灯
    for(int i = 1; i<=n; i++){
        if( i % 2 == 0) light[i] = - light[i];
        if( i % 3 == 0) light[i] = - light[i];
        if( i % 4 == 0) light[i] = - light[i];
        if( i % 5 == 0) light[i] = - light[i];
    }
    for(int i =1; i<=n; i++){
        if(light[i] > 0)    cout<<i<<" ";
    }
    cout<<endl;
    return 0;

}