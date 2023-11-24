#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+10;
int n;
struct Range{//重载"<"
    int l,r;
    bool operator< (const Range &w)const
    {
        return r < w.r;
    }
}inter[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>inter[i].l>>inter[i].r;
    }
    sort(inter, inter+n);
    int res = 0;
    int ed = -2e9;
    for(int i = 0; i < n; i++){
        if(inter[i].l >= ed){ //跟上题代码一样，只是这里区间左右相等也可以
            res++;
            ed = inter[i].r;
        }
    }
    cout<<res<<endl;
    return 0;


}