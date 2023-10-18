#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


typedef struct point
{
    int x;
    int y;
    /* data */
} point;

const int N = 100010;

double dist(point a, point b){
    double res = sqrt((a.x-b.x)*(a.x-b.x) + (a.y - b.y)*(a.y-b.y)); 
    return res;
}
point P[N];
int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>P[i].x>>P[i].y;
    }
    double res = 10000;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n;j ++){
            double dis = dist(P[i],P[j]);
            res = min(res,dis);
        }
    }
    if(res >= 10000) cout<<"INFINITY"<<endl;
    else   cout<<res<<endl;
    return 0;

}
