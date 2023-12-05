#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
ll sum1[200005],sum2[200005],a[200005];

map<ll,int> ma; 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ma[a[i]] ++;
	} 
	sort(a+1,a+1+n);
	for (int i = 1; i <= n; i++)
	{
		sum1[i] = sum1[i-1] + a[i];
	}
	for (int i = n; i >= 1; i--)
	{
		sum2[i] = sum2[i+1] + a[i];
	}
	ll ans = 1e18;
	for (int i = 1; i <= n; i++)
	{
		if( ma[a[i]] >= k )
		{
			ans = 0;
			break;
		}
		ll cost1 = 1e18;
		ll cost2 = 1e18;
		if( i >= k ) cost1 = a[i] * i - sum1[i] - (i-k);
		if( n - i + 1 >= k ) cost2 = sum2[i] - a[i] * (n-i+1) - (n-i+1-k);
		ll cost3 = (a[i] * i - sum1[i]) + (sum2[i] - a[i] * ( n - i + 1 )) - (n-k);
		ans = min(ans,cost1);
		ans = min(ans,cost2);		
		ans = min(ans,cost3);
	}
	cout << ans << '\n';
	return 0;
}

