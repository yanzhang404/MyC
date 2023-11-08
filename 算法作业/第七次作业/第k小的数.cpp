//用快排时间复杂度O(nlogn)
//快速选择算法复杂度O(n)

#include <iostream>

using namespace std;

const int N = 100010;

int n,k;
int q[N];

int quicksort(int l, int r, int k){
    if(l == r)  return q[l];
    int x = q[l], i = l - 1, j = r + 1;
    while(i < j){
        while(q[++i] < x);
        while(q[--j] > x);
        if(i < j) swap(q[i],q[j]);
    } //将数组分为两部分
    int sl = j - l + 1; //计算左边的长度
    if(k <= sl) return quicksort(l,j,k); //如果k<=sl，说明第k个数在左边，只需要对左边继续quicksort
    return quicksort(j+1,r,k-sl);//否则在右边，找第k-sl个数，就是整体第k个数
}


int main(){
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>q[i];
    }
    cout<<quicksort(0,n-1,k)<<endl;
}