#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 200005;
int n, m,ans;
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    if (n<=2 || n%2==0) {
        printf("-1");
        return 0;
    }
    for (int i=n; i>1; --i){
        if (a[i]<=0) continue;
        ans+=a[i];
        int k=i/2;
        a[k]-=a[i];
        a[k*2]-=a[i];
        
    }

   
    if (a[1]>0)  ans+=a[1];

    printf("%d", ans);
}