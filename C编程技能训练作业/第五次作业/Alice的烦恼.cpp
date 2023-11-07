#include<iostream>
using namespace  std;
const int N = 10001;
int q[N];

int main() {
    int n, k;
    cin >> n >> k;
    int sum = 0;
    double tmp;
    for (int i = 0; i < n; i ++) {
       cin >> tmp;
       q[i] = int(tmp * 100.0); //把长度乘100变成整数
       sum += q[i]; //求总长度
    }
    int l = 0, r= sum / k;  //二分法，从0到最长为sum分成k份后的长度
    while (l < r) {
        int mid = (l + r + 1) / 2; //取中点
        int s = 0; //总数
        for (int i = 0; i < n; i ++) {
            s += q[i] / mid; //每根火腿肠 / 此时的最大长度，如果比此时的最大长度小就为0，等于没选。 
        }
        if (s >= k) { //如果总数大于s，说明最大长度还不是最大的，对右半部分重复
            l = mid;
        } else { //否则就慢慢减，每次减1.
            r = mid - 1;
        }//l和r重复时，找到最大长度
    }
    double res = l / 100.0;
    printf("%.2lf\n", res);
}