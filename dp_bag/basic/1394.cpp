#include <iostream>
#include <cstring>
using namespace std;

const int mod = 100000000, MAXN = 2005;
int n, f;
int cat[MAXN];
int dp[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> f;
    for (int i = 1; i <= n; i++)
    {
        cin >> cat[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < f; j++)
        {
            dp[i][j] = dp[i - 1][j] % mod+ dp[i - 1][(j + f - cat[i] % f) % f] % mod;
        }
        dp[i][cat[i] % f] += 1;
        dp[i][cat[i] % f] %= mod;
    }
    cout << dp[n][0] % mod << endl;
    return 0;
}
