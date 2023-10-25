#include <iostream>

using namespace std;


const int N = 10e6+10;
int n, p; //学生数，增加分数的次数
int stu[N];
int res=100;
int main(){
    cin>>n>>p;
    for(int i = 1; i <= n; i++){
        cin>>stu[i];
    } 
    for(int i = 0; i < p; i++){
        int x,y,z;
        cin>>x>>y>>z;
        for(int i = x; i<=y;i++){
            stu[i]+=z;
        }
    }
    for(int i = 1; i<= n;i++){
        res = min(res,stu[i]);
    }
    cout<<res<<endl;
    return 0;
}