#include <iostream>
#include <vector>
using namespace std;

int MaxSum( vector<int> arr, int n){
    vector<int> sum(n,1); 
    int res = arr[0];
    int cur = arr[0];
    for(int i = 1; i < n; i++){
        if(cur + arr[i] > arr[i])   cur += arr[i];
        else cur = arr[i];
        res = max(res, cur);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>> arr[i];
    }
    int res = MaxSum(arr, n);
    cout<<res<<endl;
    return 0;
}