#include <iostream>

using namespace std;


const int N = 1e7+10;

int q[N];
int n;

int bsearch(int q[N], int n){
    int l = 0,r = n - 1;
    if(q[0] < q[r]) return q[0];
    while(l < r ){
        int mid = (l + r ) / 2;
        if(q[mid] < q[0])   r = mid;
        else    l = mid + 1;
    }
    return q[l];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>q[i];
    }
    int res = bsearch(q,n);
    cout<<res<<endl;
    return 0;
}