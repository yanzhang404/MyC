#include <iostream>
#include "vector"

using namespace std;

int main() {
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
        num[i] = abs(num[i]);
    }
    int ans = 0;
    for(int i=1;i<n-1;i++){
        int tmpl = 0,tmpr = 0;
        for(int j=0;j<i;j++){
            if(num[i]>num[j]){
                tmpl++;
            }
        }
        for(int j=i+1;j<n;j++){
            if(num[i]>num[j]){
                tmpr++;
            }
        }
        ans+=min(tmpl,tmpr);
    }
    cout<<ans<<endl;
    return 0;
}