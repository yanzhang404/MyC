#include <iostream>
#include <algorithm>

using namespace std;


const int N = 10010;

int main(){
    int n, k;
    cin >> n >> k;
    int nums[N];
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    sort(nums, nums + n);
    int cnt = 1;
    int latest = nums[0];
    for(int i = 0; i < n; i++){
        if(latest != nums[i]){
            cnt++;
            latest = nums[i];
        }
        if ( k == cnt){
            cout<<latest<<endl;
            break;
        }
    }
    if(k > cnt){
        cout<<"NO RESULT"<<endl;
    }
    return 0;
}