//计算a^k mod p,
//快速幂的做法可以在log(k)的时间复杂度内完成
// 1 <a,k,p<2*10^9
//只要把k用二进制表示

#include <iostream>

using namespace std;
typedef long long LL;

//a^b mod p
int qmi(int a, int b, int p){
    int res = 1;
    while(b){
        if(b & 1) res = (LL)res*a % p; //如果b的末位为1， 则将这个a加入到答案中   
        b = b >> 1;//右移b
        a = (LL)a*a % p;  //每次更新a
    }
    return res;
}   


int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a,b,p;
        scanf("%d%d%d",&a,&b,&p);
        printf("%d\n",qmi(a,b,p));
    }
    return 0;
}