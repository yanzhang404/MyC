#include <iostream>
#include <algorithm>

using namespace std;
struct coin{
    double m;
    double v;
    double p;
};
const int N =110;

bool cmp(coin a, coin b){
    return a.p > b.p;
}

int n, T;
coin c[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>T;
    for(int i = 0; i < n; i++){
        cin>>c[i].m>>c[i].v;
        c[i].p = c[i].v / c[i].m;
    }

    sort(c+1,c+n+1,cmp);
    double res = 0;
    for(int i = 0; i < n; i++){
        if(c[i].m <= T){
            res+=c[i].v;
            T-=c[i].m;
        }
        else{
            res += c[i].p * T;
            break;
        }
    }
    printf("%.2f\n",res);
    return 0;




}