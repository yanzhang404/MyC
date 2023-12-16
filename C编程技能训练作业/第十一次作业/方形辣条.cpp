#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nums;
vector<bool> st;



bool dfs(int start, int cur, int length, int cnt){
    if(cnt == 3)    return true;
    if(cur == length)   return dfs(0,0,length,cnt+1);

    for(int i = start; i <nums.size(); i++){
        if(st[i]) continue;
        if(cur + nums[i] <= length){
            st[i] = true;
            if(dfs(i + 1, cur + nums[i], length, cnt))  return true;
            st[i] = false;
        }

        if(!cur || cur + nums[i] == length) return false;
        while(i + 1 < nums.size() && nums[i + 1] == nums[i])
            i++;
    }

    return false;
}

bool square(vector<int>& nums){
    st.resize(nums.size());
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum+=nums[i];
    }
    if(sum % 4) return false;
    sum /= 4;
    sort(nums.begin(), nums.end(), greater<int>());
    return dfs(0,0,sum,0);
}


int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    bool ans = square(nums);
    if(ans) cout<<"yes"<<endl;
    else    cout<<"no"<<endl;
    return 0;
}