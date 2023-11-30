#include <iostream>
#include <algorithm>
using namespace std;


const int N = 1e5+10;

int t[N];
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>t[i];
    }
    sort(t+1,t+n+1);
    int sum = 0;
    for(int i = 1; i< n; i++){
        int temp =0;
        for(int j = 0; j < i;j++){
            temp+=t[j];
        }
        sum+=temp;
    }
    cout<<sum<<endl;
    return 0;
}