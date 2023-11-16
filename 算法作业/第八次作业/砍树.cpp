//跟之前做过的切烤肠，分披萨一个题型

#include <iostream>
using namespace std;

const int N = 1e5+10;
int q[N];
int n, k;

int main(){
    cin>>n>>k;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>q[i];
        sum+=q[i];
    }
    int l = 0, r = sum / k;
    while( l < r){
        int mid = ( l + r + 1 ) / 2;
        int s = 0;
        for(int i = 0; i < n; i++){
            s += q[i] / mid;
        }
        if(s < k) r = mid - 1; // 判断按mid长度计算得到的总数与所需要的分数k之间的比较
                               // 如果s比k小，说明按这个长度分不够，所以答案在l，mid-1之间
        else l = mid; 
    }
    cout<<l<<endl;
    return 0;
}