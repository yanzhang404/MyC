#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int N = 255;

int main(){
    stack<char> brac;
    char c;
    while(1){
        cin>>c;
        if(c == '@')    break;
        if(c == '(') brac.push('('); //左括号入栈
        else if(c == ')') {
            if(brac.empty()){//右括号出现但栈已空则不匹配
                cout<<"NO"<<endl;
                return 0;
            }
            else    brac.pop();//否则栈头元素出栈
        }
    }
    if(brac.empty())    cout<<"YES"<<endl; // 结束后栈空则YES，否则则NO
    else    cout<<"NO"<<endl;
    return 0;
}