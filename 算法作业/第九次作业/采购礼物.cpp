#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5+10;
int n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin>>p[i];
    }
    sort(p.begin(),p.end());
    int res = 0;
    for(int i = 0; i < n; i++){
      if(m>=p[i]){
            m-=p[i];
            res++;
      }
      else  break;
    }
    cout<<res<<endl;
    return 0;
}