#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int n;
const int N = 1010;
int q[N];
int sum[N];
int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>q[i];
    }
    int s = 0;
    int res = INT_MIN;
    for(int i = 0; i < n; i++){
        if(s < 0) s = 0;
        s += q[i];
        res = max(res, s);
        }
    cout<<res<<endl;
    return 0;
}