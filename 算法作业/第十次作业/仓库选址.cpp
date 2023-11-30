#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int N = 1e5+10;
int n;
int A[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>A[i];
    }
    sort(A+1,A+n+1);

    int res = 0;
    for(int i = 1; i <= n;i++){
        res+=abs(A[i]-A[1+n/2]);
    }
    cout<<res<<endl;
    return 0;
}