# dp算法

dp表示考虑状态表示(集合，属性)，状态表示

## 一. 0-1背包问题

最原始的代码是利用二维数组dp[i][j]存放前i个物品容量为j时的最大价值，代码如下：

```cpp
#include <iostream>

using namespace std;

const int N = 1010;
int n,m;//n件物品，背包容量为m
int v[N],w[N]; // 体积v，价值w

int f[N][N]; //f[i][j]前i件物品，容量为j时候的最大价值
int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>v[i]>>w[i];
    }
    for(int i = 1; i <= n; i++){ // 
        for(int j = 0; j <= m; j++){
            f[i][j] = f[i-1][j];
            if(j >= v[i]){
                //要么前i-1件不超过体积j的价值最大，
                //要么加上第i件后价值最大，所以是前i-1件不超过体积j-v[i]的价值加上第i个的价值
                f[i][j] = max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
            }
        }
    }

    cout<<f[n][m]<<endl;
    return 0;

}
```

dp[i][j]可以优化为一维数组，

当变成一位dp[j]的时候，dp[j]只代表了，容量为j的时候的最大价值，省去了到底是前几个物品导致的，但是最外层还是有i的循环，每一轮dp[j]=dp[j]还是等价于dp[i][j] = dp[i-1][j]，因为没执行之前的dp[j]依然还是上一轮dp[i-1]中的最大价值，而当j>=v[i]的时候，计算f[j] = max(f[j], f[j-v[i]]+w[i])的值，但如果j从小到大的话，<u>此时的f[j]已经被更新过了，不是第i-1轮中的f[j]，因此不能从小到大更新</u> 这句错了，要关注的不是f[j]，而是f[j-v[i]]，我们需要的是f[i-1][j-v[i]]，**但是因为j-v[i]小于j，因此肯定在第i轮中先被算出，也就是如果改成一维的话，f[j-v[i]]是第i轮的**，也就是前i个元素容量为j的最大价值，但我们需要的是前i-1个物品。那这样的话，如果我们从大到小呢？

f[j] = max(f[j], f[j-v[i]] + w[i])，**第i轮中，f[j-v[i]]还没被算过，也就是说这里的f[j-v[i]]还是第i-1轮的值**，完美解决了问题。另外可以免去v[N],w[N]数组，只需要在每一轮里进行比较就行。最终代码如下：

```cpp
#include <iostream>

using namespace std;

const int N = 1010;
int n,m;//n件物品，背包容量为m
int f[N]; //容量为j的背包的最大价值
int main(){
    cin>>n>>m;
    for(int i = 1; i <=n; i++){
        int v,w;
        cin>>v>>w;
        for(int j = m; j >=v; j--){
            f[j] = max(f[j],f[j-v]+w);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
```

## 二.多重背包

### 2.1朴素做法

  每种物品多了一个数量的限制，所以在每次循环选择最大值的时候，需要考虑选1个，选2个，...选si个。也就是再加一重循环，时间复杂度$O(n^3)$

<sub>感觉所谓可以选多个物品其实可以看成是k个i物品组成了一个新物品，这个新物品的重量是w[i]*k，然后这个新物品只能是选和不选两种情况。将所有新的物品重新编号，就和01背包一模一样了。</sub>

当数量级不大的时候，可以选择此方法，代码如下：

```cpp
#include <iostream>
using namespace std;
const int N = 110;
int n, m;
int f[N]; //容量为i时的最大价值。
int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        int v,w,s;
        for(int j = m; j>=v; j--){
            for(int k = 0; k <= s && k*v<=j;k++){
                f[j] = max(f[j],f[j-k*v]+k*w);
            }
        }
    }
    cout<<f[m]<<endl;
}
```

### 2.2二进制优化法

正如上面的所说，上面的是将s个物品用s个数来表示，而任何数可以用log(s)向上取整个数组成，通过二进制法，如7 = 111，可以由1，2，4组成，因此任何一个数可以通过二进制法，拆成log(s)份，组成新的物品，从而变成0-1背包问题，代码如下：

```cpp
//增大数量级
//采用二进制优化方法

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2010; //从200变成2000
int n, m;
int f[N];
struct good{ //用结构体来表示物品
    int v,w;
};
int main(){
    vector<good> goods;//因为不知道拆出来的新的物品有多少，
                       //因此用一个vector来存放
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        int v,w,s;
        cin>>v>>w>>s;
        for(int k = 1; k <=s; k = k*2){ 
            s-=k;//每次拆掉2^k次方
            good temp;
            temp.v = k*v;
            temp.w = k*w;
            goods.push_back(temp);
        }//最后将剩下的数字再组成一个新的物品
        good temp;
            temp.v = s*v;
            temp.w = s*w;
        goods.push_back(temp);
    }
    //现在变成了0-1背包问题
    for(int i = 0; i < goods.size(); i++){
        for(int j = m;j>=goods[i].v;j--){
            f[j] = max(f[j], f[j-goods[i].v]+goods[i].w);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
```

## 三. 完全背包问题

完全背包中，每种物品有无限数量可以选择。

代码与0-1背包很像，其中需要推导的一步是，

因为第i个物品有无数个，因此前i个物品总体积为j的集合可以划分为，第i个物品选0个，1个，2个，...，n个

因此

$f[i][j]=max(f[i-1][j], f[i-1][j-v]+w,f[i-1][j-2v]+2w,...f[i-kv]+kw+...)$

$f[i][j-v]=max(f[i-1][j-v], f[i-1][j-2v]+w,f[i-1][j-3v]+2w,...f[i-(k+1)v]+kw+...)$

则

$f[i][j] = max(f[i-1][j], f[i][j-v]+w)$

而我们记得0-1背包问题的表达式为

$f[i][j] = max(f[i-1][j],f[i-1][j-v]+w)$

因此在代码里，j的循环，只需要将0-1背包里的从大到小改为从小到大即可，因为更新f[i][j]需要的正是f[i][j-v]的值。因此代码如下：

```cpp
#include <iostream>

using namespace std;

const int N = 1010;
int n,m;//n件物品，背包容量为m
int f[N]; //容量为j的背包的最大价值
int main(){
    cin>>n>>m;
    for(int i = 1; i <=n; i++){
        int v,w;
        cin>>v>>w;
        for(int j = v; j <=m; j++){
            f[j] = max(f[j],f[j-v]+w);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
```
