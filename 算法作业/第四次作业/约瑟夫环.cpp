#include <iostream>
#include <list>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    list<int> num;
    for(int i = 1; i <= n; i++) num.push_back(i);
    auto it = num.begin();
    int k = 0;
    while(!num.empty()){
        k = k % m + 1;
        if( k == m){
            auto t = it;
            it++;
            cout<<*t<<" ";
            num.erase(t);
        }
        else it++;
        if(it == num.end())   it = num.begin();
    }
    return 0;

}
