#include <iostream>

using namespace std;
const int N = 21;
int n;
int IfC[21];
void print(){
    for(int i = 1; i <= n; i++){
        if(IfC[i] == 1) cout<<i<<" "; //将选择的全部遍历
    }
    cout<<endl;
}
void enumerate(int step){
    if( step > n){
        print();
        return;
    }
    IfC[step] = 1; //选择step，
    enumerate(step + 1);//继续递归
    IfC[step] = 0;  //不选step
    enumerate(step + 1);//继续递归
}

int main(){
    cin>>n;
    enumerate(1);
    return 0;
}