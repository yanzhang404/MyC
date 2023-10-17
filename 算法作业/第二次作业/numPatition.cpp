#include <iostream>
#include <string>
#include <set>
using namespace std;


int n, k;


void patition(int n, int k, vector<int> res){
    if(k == 1){
        res.push_back(n);
        sort(res.begin(),res.end());
        for(int i = 0; i< res.size(); i++)
                cout<<res[i]<<" "; 
        cout<<endl;
        res.pop_back();
        return;
    }
    
    for(int i =1; i<n; i++){
        res.push_back(i);
        patition(n-i,k-1, res);
        res.pop_back();
    }
}

int main(){
    cin>>n>>k;
    vector<int> res;
    patition(n,k,res);
    return 0;
}
    

// 6 1 5
// 5 1 4
//   1 1 4
// 6 1 5
// 5 2 3
//   1 2 3
// 6 1 5
// 5 3 2
//   1 3 2
// 6 2 4
// 4 1 3 
//   2 1 3
// 6 2 4
// 4 2 2
//   2 2 2
// 用 set？
