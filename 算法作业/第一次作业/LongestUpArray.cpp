#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int nums[n];
    int res =1;
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    vector<int> len(n,1);
    
    for(int i = 1; i<n; i++){
        if(nums[i]>nums[i-1])   len[i] = len[i-1]+1;
        else    len[i] = 1;
        res = max(res,len[i]);
    }
    cout<<res<<endl;
    return 0;



}