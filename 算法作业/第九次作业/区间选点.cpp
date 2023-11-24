#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+10;

struct Range{//重载"<"
    int l,r;
    bool operator< (const Range &w)const
    {
        return r < w.r;
    }
}range[N];


Range inter[N];
int n;

int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>inter[i].l>>inter[i].r;
    }
    sort(inter, inter+n);
    int res = 0;
    int ed = -2e9;
    for(int i = 0; i < n; i++){
        if(inter[i].l > ed){
            res++;
            ed = inter[i].r;
        }
    }
    cout<<res<<endl;
    return 0;


}