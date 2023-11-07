#include <iostream>
#include <string>
 
using namespace std;
 
const int N = 105;

string s[N][2];
int w[N],v[N];
int f[2][N][20005];
int n,m;

int main()
{
 std::ios::sync_with_stdio(false);
 cin.tie(0); 
 cout.tie(0);
 cin>>n;
 int sum=0;
 for (int i=1;i<=n;i++){
  cin>>w[i];
  
 }
 for (int j=1;j<=n;j++) {
  cin>>v[j];
  sum+=v[j]-w[j];
 }
 for (int i=0;i<=1;i++){
  for (int j=0;j<=n;j++){
   for (int k=0;k<=2*sum;k++){
    f[i][j][k]=1e9;
   }
  }
 }
 f[0][0][sum]=0;
 
 int num=1e9,ans=1e9;
 for (int i=1;i<=n;i++){
  for (int j=0;j<=i;j++){
   for (int k=0;k<=2*sum;k++){
    f[i%2][j][k]=1e9;
    if(k+w[i]<=2*sum)f[i%2][j][k]=min(f[i%2][j][k],f[(i-1)%2][j][k+w[i]]+w[i]);
    if(k-v[i]+w[i]>=0&&j>=1)f[i%2][j][k]=min(f[(i)%2][j][k],f[(i-1)%2][j-1][k-v[i]+w[i]]);
    if(i==n&&f[i%2][j][k]<1e9&&k>=sum){
     if (j<num){
      num=j;
      ans=f[n%2][j][k];
     }else if (j==num) ans=min(ans,f[n%2][j][k]);
    }
    //if(i==1&&j==0)cout<<f[i%2][j][k]<<" ";
   }
  }
 }
 //cout<<f[0][2][sum]<<endl;
 cout<<num<<" "<<ans<<endl;
 
 //if (m<n) cout<<0<<endl;
 //system("pause");
    return 0;
}