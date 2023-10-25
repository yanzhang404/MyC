#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10000010;
int a[N];
int n;
vector<int> nums;

void moveZero(vector<int> nums){
    int left = 0, right = 0;
    int n = nums.size();
    while(right < n){
        if(nums[right]){
            swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }

    for(int i = 0; i < n; i++){
        if(i == n - 1)  cout<<nums[i];
        else cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int slow = 0, fast = 0;
    while(fast < n){
        if(a[fast] != 0){
            if(slow != fast){
                a[slow] = a[fast];
                a[fast] = 0;
            }
            slow++;
        }
        fast++;
    }
    for(int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
    cout<<endl;
    return 0;

}
