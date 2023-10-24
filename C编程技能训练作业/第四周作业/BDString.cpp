#include <iostream>
#include <algorithm>
using namespace std;
typedef long long lon;
 
lon a[65];
 
lon get(lon x)
{
	if(x == 0) return 0;
	
	for(int i = 1; i <= 60; i++)
	{
		if(a[i] == x)
			return x / 2 + 1;
		
		if(x < a[i])
			return x - a[i-1] + get(a[i] - x);
	}
}
 
int main()
{
	for(int i = 1; i <= 60; i++)
	a[i] = a[i-1] * 2 + 1;
	
	int T;
	cin >> T;
	while(T--)
	{
		lon l, r;
		cin >> l >> r;
	//	cout << get(l-1) << endl;
		cout << get(r) - get(l-1) << endl;
	}
	
	return 0;
}