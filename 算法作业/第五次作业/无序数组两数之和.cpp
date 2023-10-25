#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int n; //元素个数
vector<int> nums;
int target; //目标值

void judge(vector<int> nums, int target){
    unordered_map<int,int> map;
    for(int i = 0; i < nums.size(); i++){
        auto it = map.find(target-nums[i]);
        if(it != map.end()){
            cout<<it->second<<" "<<i<<endl;
            return;
        }
        map[nums[i]] = i;
    }
    cout<<-1<<" "<<-1<<endl;

}


int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    cin>>target;
    judge(nums,target);
    return 0;
}