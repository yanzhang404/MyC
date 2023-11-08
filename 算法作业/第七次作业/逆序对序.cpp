#include <iostream>

using namespace std;


typedef long long LL;

const int N = 100010;

int n;
int q[N],temp[N];
LL mergesort(int l ,int r){
    if(l >= r)  return 0;
    int mid = (l + r) / 2;
    LL res = mergesort(l,mid) + mergesort(mid+1,r);//逆序对都在一侧的情况
    int i = l,j = mid+1;
    int k = 0;
    while( i <= mid && j <= r){
        if(q[i] <= q[j]){
            temp[k++] = q[i++];
        }
        else{
            temp[k++] = q[j++];
            res += mid - i + 1;//加上逆序对分在两侧的情况，当q[i]>q[j]时，i后面的都比q[j]大
            //就有mid - i + 1 个逆序对
        }
    }
    while(i <= mid){
        temp[k++] = q[i++];
    }
    while(j <= r){
        temp[k++] = q[j++];
    }
    for(int i = l,j=0;i<=r;i++,j++){
        q[i] = temp[j];
    }
    return res;
}



int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>q[i];
    }
    cout<<mergesort(0,n-1)<<endl;
}