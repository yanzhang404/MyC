// 0-1背包 
#include <iostream>

using namespace std;
int n , v; 
int v_i[20]; // 第i个物品的体积 
int w_i[20]; // 第i个物品的价值 
int bestw; // 最优价值 ，最优解 
int x[20]; // 物品放入状态数组
int curv; // 当前体积
int curw; //当前价值 


int bound(int x){ //计算价值上界
    int rw = 0; //rp:第x个商品~第n个商品全部装入的总价值,先初始化为0
    while(x<=n) 
    {
        rw+=w_i[x];
        x++;
    }
    return rw+curw; //返回当第t个商品不装时,返回前t个商品(不包括第t个)的总价值+剩余的全部商品价值
}
void dfs(int step){

    if(step > n){ //某个分支搜索到叶子节点 ，找到一个可行解 
        if(curw > bestw){ //如果当前价值大于最优价值，更新最优解 
            bestw = curw; 
        } 
        return ;
    }

    if(curv + v_i[step] <= v){ //判断放入第step个物品不超重，尝试放入 
        x[step] = 1; //标记放入
        curv += v_i[step]; // 累加体积
        curw += w_i[step]; //累加价值 
        dfs(step+1); 
        curv -= v_i[step]; // 回溯，恢复当前体积 
        curw -= w_i[step]; // 回溯，恢复当前价值 
    }

    if(bound(step + 1) > bestw){ //判断不放入第step个物品，是否还有必要继续在该分支下搜索 
        x[step] = 0; // 尝试不放入第i个物品
        dfs(step+1); 
    } 
}

int main(){
    cin >> n >> v;
    for(int i = 1 ; i <= n; i++){
        cin >> v_i[i] >> w_i[i];
    } 

    dfs(1);

    cout << bestw << endl;
    return 0;
}