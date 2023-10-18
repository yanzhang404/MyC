#include <iostream>
#include <set>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    set<int> num;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        num.insert(temp);
    }
    int len = num.size();
    set<int>::iterator it;
    if(len < k) cout<<"NO RESULT"<<endl;
    else{
        for(it = num.begin(); it != num.end(); it++){
            cnt++;
            if(cnt == k){
                cout<<*it<<endl;
            }
        }
    }
    return 0;
}