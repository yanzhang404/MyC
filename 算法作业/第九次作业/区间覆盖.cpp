#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10;

struct Range{
    int l,r;
    bool operator< (const Range & w) const{
        return l < w.l;
    }
}range[N];
int s,t,n;

int main(){
    cin>>s>>t;
    cin>>n;
    for(int i = 0; i < n;i++){
        cin>>range[i].l>>range[i].r;
    }
    sort(range,range+n);
    bool success = false;
    int res = 0;
    for(int i = 0; i < n; i++){
        int j = i, r = -2e9;
        while( j < n && range[j].l <=s){
            r = max(r, range[j++].r);
        }
        if(r < s){
            res = -1;
            break;
        }
        res++;
        if(r >= t){
            success = true;
            break;
        }
        s = r;
        i = j - 1;
    }
    if(!success) res = -1;
    cout<<res<<endl;
    return 0;
}