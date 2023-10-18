#include <iostream>  
#include <set>  

using namespace std;  

int main()  
{  
    int n;
    set<int> num;
    cin>>n;
    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        num.insert(temp);
    }
    set<int>::iterator it;
    cout<<num.size()<<endl;
    
    for(it = num.begin(); it!=num.end();it++){
        cout<<*it<<" ";
    } 
    return 0;  
}  
