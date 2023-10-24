#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

//分治算法求二维平面点的最短距离

typedef struct point   //点的结构体
{
    int x;
    int y;
} pt;

bool cmp_x(const pt& a, const pt& b){  //比较x坐标的大小，如果横坐标相同则比较纵坐标大小
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp_y(const pt& a, const pt& b){
    return a.y < b.y;
}

const int N = 100010;

int n;

vector<pt> a(N);  //创建一个点的数组

double mindist; 

void upd_ans(const pt& a, const pt& b){   //更新最短距离
    double dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + .0);
    if(dist < mindist)  mindist = dist;
}


void rec (int l, int r){
    if(r - l <= 3){  //当点数很小的时候暴力求出这些点中的最小距离
        for(int i = l; i <= r; i++){
            for(int j = i + 1; j <=r; j++) upd_ans(a[i],a[j]);
        }
        sort(a.begin() + l, a.begin() + r + 1, &cmp_y);  //将这些点按纵坐标大小排序
        return;
    }

    int m = (l + r) >> 1; // 将数组一分为二
    int midx = a[m].x;
    rec(l,m);//处理左边
    rec(m+1,r);//处理右边
    //将两部分按y坐标进行归并排序
    inplace_merge(a.begin() + l, a.begin() + m + 1, a.begin() + r + 1, &cmp_y);

    //设置一个新的数组，存放与中点x距离小于mindist的点
    static pt t[N];
    int tsz = 0;
    for(int i = l; i <= r; i++){
        if( abs(a[i].x) - midx < mindist){
            for(int j = tsz - 1; j >= 0 && a[i].y -t[j].y < mindist; j--)
                upd_ans(a[i],t[j]);
            t[tsz++] = a[i];
        }
    }
}


int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a.begin(), a.begin() + n, &cmp_x);
    mindist = INT_MAX;
    rec(0, n - 1);
    if(mindist >= 10000)    cout<<"INFINITY"<<endl;
    else    printf("%.4f\n",mindist); // 本题需要保留4位小数，不保留就错了
    return 0;

}
