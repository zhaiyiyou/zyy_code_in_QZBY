#include <iostream>
#include <vector>
using namespace std;

int t, n, m;
int a[1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= t; i++)
    {
        vector<int> dp(m + 1);

        for (int j = 1; j <= m; j++)
        {
            dp[j] = j;
        }
        for (int j = 1; j <= n; j++)
        {
            for (int k = a[i][j]; k <= m; k++)
            {
                dp[k] = max(dp[k], dp[k - a[i][j]] + a[i + 1][j]);
            }
        }
        m = max(m, dp[m]);
    }
    cout << m << endl;
    return 0;
}