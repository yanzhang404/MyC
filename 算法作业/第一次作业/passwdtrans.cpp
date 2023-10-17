#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int s[n];
    for(int i=0; i < n; i++){
        cin>>s[i];
    }
    vector<int> passwd(s,s+n);
    vector<int> realpw(n);
    for(int i = 0; i < n; i++){
        realpw[i] = passwd[0];
        passwd.erase(passwd.begin());
        int temp = *passwd.begin();
        passwd.push_back(temp);
        passwd.erase(passwd.begin());
    }
    for(int i =0; i< n; i++){
        cout<<realpw[i]<<" ";
    }
    cout<<endl;
    return 0;
}