#include <iostream> 
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <limits.h>
#include <set>
using namespace std;

void fun(vector<vector<int> >& res,const vector<int>& nums, int index, vector<int>& seq){
    if (index == nums.size())
    {
        res.push_back(seq);
    }
    else
    {
        seq.push_back(nums[index]);
        fun(res, nums, index + 1, seq);
        seq.erase(seq.end() - 1);
        fun(res, nums, index + 1, seq);
    }
    
    
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    //sort(nums.begin(), nums.end(), greater<int>());
    vector<vector<int> > res;
    vector<int> seq;
    fun(res, nums, 0, seq);
    for (auto r : res){
        for (int i = 0; i < r.size(); i++)
        {
            cout << r[i]<<" ";
        }
        cout<<endl;
    }
}
