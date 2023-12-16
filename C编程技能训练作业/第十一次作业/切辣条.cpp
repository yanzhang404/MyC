#include <iostream>
#include <algorithm>


using namespace std;

const int N = 64;
int n;
int latiao[N];
bool st[N];
int sum,length;

bool dfs(int u, int cur, int start){
    if( u * length == sum)  return true;
    if(cur  == length)   return dfs(u + 1, 0, 0);
    for(int i = 0; i < n; i++){
        if(st[i]) continue;
        if(latiao[i] + cur <= length){
            st[i] = true;
            if(dfs(u, cur + latiao[i], i + 1)) return true;
            st[i] =false;
        }

        if(!cur || cur + latiao[i] == length) return false;
        while(i + 1 < n && latiao[i + 1] == latiao[i])  i++;
    }
    return false;
}


int main(){
    cin>>n;
    for(int i = 0; i <n; i++){
        int l;
        cin>>l;
        latiao[i] = l;
        sum += l;
        length = max(length,l);
    }

    sort(latiao, latiao+n);
    reverse(latiao, latiao + n);
    while(length){
        if(sum % length == 0 && dfs(0,0,0)){
            cout<<length<<endl;
            break;
        }
        length++;
    }
    return 0;
}