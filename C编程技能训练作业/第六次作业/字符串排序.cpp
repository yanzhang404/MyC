#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#define LL long long int
using namespace std;

const int N = 100050;
const LL INF = 1e15;
LL cost[N];
LL dp[N][2];
vector<string> vs;
vector<string> rvs;

int main(int argc, char **argv)
{
  memset(dp, 0x3f, sizeof(dp));
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> cost[i];
  }
  for (int i = 0; i < n; ++i)
  {
    string str;
    cin >> str;
    vs.push_back(str);
    reverse(str.begin(), str.end());
    rvs.push_back(str);
  }

  dp[0][0] = 0, dp[0][1] = cost[0];
  for (int i = 1; i < n; ++i)
  {
    if (vs[i] >= vs[i - 1])
    {
      dp[i][0] = dp[i - 1][0];
    }
    if (vs[i] >= rvs[i - 1])
    {
      dp[i][0] = min(dp[i][0], dp[i - 1][1]);
    }

    if (rvs[i] >= vs[i - 1])
    {
      dp[i][1] = dp[i - 1][0] + cost[i];
    }
    if (rvs[i] >= rvs[i - 1])
    {
      dp[i][1] = min(dp[i][1], dp[i - 1][1] + cost[i]);
    }
  }

  LL res = min(dp[n - 1][0], dp[n - 1][1]);
  if (res < INF)
    cout << res << endl;
  else
    cout << -1 << endl;
  return 0;
}
