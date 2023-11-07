#include <iostream>
#include <math.h>

using namespace std;

const int N = 100010;
const float pi = acos(-1.0);
int n, m;
long long p[N]; //存的是每块披萨的面积
long long sum; //所有披萨加起来的面积

int main(){
    cin>>n>>m;
    int k = m+1; // 份数
    for(int i = 0; i < n; i++){
        long long temp;
        cin>>temp;
        p[i] = int(temp*temp*pi*100000.0);
        sum += p[i]; // 总面积
    }
    long long l = 0, r = sum / k;
    while( l < r){
        long long mid = (l + r + 1LL)/2;
        long long s = 0;
        for(int i = 0; i < n; i++){
            s += p[i] / mid;
        }
        if( s >= k){
            l = mid;
        }
        else{
            r = mid - 1;
        }

    }
    double res = l / 100000.0;
        printf("%.4lf\n", res);
}