#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int N = 10e5+10;

int n;
int nums[N];
int cnt[N]; //计算每个i出现的次数
int res; // 结果
int main(){
    cin>>n;
    for(int i =  0; i < n; i++){
        cin>>nums[i];
    }

    for(int i=0,j=0;j < n; j++){
        cnt[nums[j]]++; //计算nums[j]出现的次数
        while(cnt[nums[j]] > 1){ //如果超过1次
            cnt[nums[i]]--;//开始移动滑动窗口直到nums[j]的个数重新变成1
            i++;
        }
        res = max(res,j-i+1); //结束后更新答案
    }
    cout<<res<<endl;
    return 0;

}