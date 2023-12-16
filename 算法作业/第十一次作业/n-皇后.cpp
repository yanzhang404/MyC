#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int cnt; //记录已经求到第几个答案 
int a[20]; //记录每行皇后放的位置 

bool flag1[20];
bool flag2[40]; 
bool flag3[40];

// flag1[j]表示第j列有没有皇后
// flag2[i + j]表示行列和为i+j有没有皇后
// flag3[i - j + n]表示行列差为i-j+n有没有皇后

// 排列树 
void dfs(int step) // step代表第几行 
{
    if(step > n) { // 找到一个可行解后，打印 
        if(cnt++ == k) exit(0); //超过了k
        // 打印一组可行解 
        for(int i = 1; i <= n; i++) 
            cout << a[i]  << " ";
        cout << endl; 
    }

    // 每行挨个位置尝试  1 ~ n 
    for(int y = 1 ; y <= n; y++){
        // 如果step行第y个位置冲突，则剪枝
        int x = step;

        if(flag1[y] || flag2[x + y] || flag3[x-y+n] ) continue; 

        a[x] = y;

        flag1[y] = true;
        flag2[x + y] = true;
        flag3[x-y+n] = true;

        dfs(x + 1); // 继续下一行 

        flag1[y] = false;
        flag2[x + y] = false;
        flag3[x-y+n] = false;
    }
}

int main(){
    cin >> n >> k;
    dfs(1);
    return 0;
}
