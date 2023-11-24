#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=100001;
int maxn = -1;
int n, m, a[1000010];
int l = maxn, r = 1000000000;
int judge(int num){
    int now = 0;
    int tot = 0;
    for(int i=1;i<=n;i++){
        if(now+a[i]<num){
            now += a[i];
        }
        else if(now+a[i]==num){
            now = 0;
            tot++;
        }
        else if(now+a[i]>num){
            now = a[i];
            tot++;
        }
    }
    if(now) tot++;  //如果还有剩余的一个值，那么这个单独算一个段
    if(tot>m)return 0;
    else return 1;

}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        maxn = max(a[i], maxn);
    }
    int l = maxn, r = 1000000000;
    if(n==m){
        cout << maxn;
        return 0;
    }
    while(l<r){
        int mid = (l+r) >> 1;
        if(judge(mid)==1){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << r;
    return 0;
}