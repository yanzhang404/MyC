#include <iostream>

using namespace std;


const int N = 100010;
int n,q;
int nums[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    while(q--){
        int k;
        cin>>k;
        int l = 0, r = n - 1;
        while(l < r){//先二分查找左边界，没有直接输出-1 -1
            int mid = (l + r) / 2;
            if(nums[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if( nums[l] != k)   cout<<"-1 -1"<<endl;
        else{
            cout<<l<<' ';
            int l = 0, r = n - 1; //再二分查找右边界
            while(l < r){
                int mid = (l + r + 1) / 2;
                if(nums[mid] <= k)  l = mid;
                else r = mid - 1;
            }
            cout<<l<<endl;
        }
    }
    return 0;
}