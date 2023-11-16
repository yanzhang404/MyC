#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


const int N = 1e5+10;
int n, m;
int q[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int sum;
    int maxq = INT_MIN;
    for(int i = 0; i < n; i++){
        cin>>q[i];
        sum = sum+q[i];
        maxq = max(maxq, q[i]);
    }
    int l = maxq, r = sum;
    while(l < r ){
        int mid = (l + r) / 2;
        int s = 0, num = 0;
        for(int i = 0; i < n; i++){
            if(s+q[i]<=mid){
                s += q[i];
            }
            else{
                s = q[i];
                num++;
            }
        }
        if(num < m) r = mid;  //如果按照这个最大值得出的段数比我们规定的段数少，
        else l = mid + 1;
    }
    cout<<l<<endl;
    return 0;



}