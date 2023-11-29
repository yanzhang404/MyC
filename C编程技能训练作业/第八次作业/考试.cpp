#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);

    for(int i = 0; i < n; i++){
        cin>>l[i];
        cin>>r[i];
    }

    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    long long sum = n;
    for(int i = 0; i < n; i++){
        sum+=max(l[i],r[i]);
    }
    cout<<sum<<endl;

    return 0;
}