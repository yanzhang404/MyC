#include <iostream>
#include <string>

using namespace std;

string s;

int main(){
    cin>>s;
    int n = s.length()-1;
    int i = 0;
    while( i < n){
        if(s[i] != s[n]){
            cout<< "No" <<endl;
            return 0;
        }
        i++;
        n--;
    }
    cout<< "Yes" <<endl;
    return 0;

}