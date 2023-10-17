#include <iostream>
#include <string>

using namespace std;

bool IsPN(int n){
    string str = to_string(n);
    string reverseStr = str;
    reverse(reverseStr.begin(),reverseStr.end());
    return str == reverseStr;
}


int main(){
    int n;
    cin>>n;
    if(IsPN(n))    cout<<"true"<<endl;
    else    cout<<"false"<<endl;
    return 0;
}