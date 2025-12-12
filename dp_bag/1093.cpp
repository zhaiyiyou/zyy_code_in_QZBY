#include <bits/stdc++.h>
using namespace std;
long long n, m, w[25], c[25], dp[21][2000001] = {0}, maxx[21];
int main()
{
    cin >> n >> m;
    maxx[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        maxx[i] = maxx[i - 1] + w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxx[i]; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (w[i] <= j)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + c[i]);
            }
        }
    }
    long long ma = -1;
    for (int i = 0; i <= m; i++)
    {
        ma = max(ma, dp[n][i]);
    }
    cout << ma;
    return 0;
}