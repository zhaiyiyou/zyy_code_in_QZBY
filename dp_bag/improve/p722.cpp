#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, t, s = 0;
    ios::sync_with_stdio(false);
    cin >> n >> t;
    vector<int> c(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        s += v[i];
    }
    vector<int> dp(s + t + 1, 1e8);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int m = log(c[i] + 1) - 1;
        for (int j = 0; j <= m; j++)
        {
            int x = 1 << j;
            for (int k = v[i] * x; k <= s + t; k++)
                dp[k] = min(dp[k], dp[k - v[i] * x] + x);
        }
        int x = c[i] - (1 << (m + 1)) + 1;
        for (int k = v[i] * x; k <= s + t; k++)
            dp[k] = min(dp[k], dp[k - v[i] * x] + x);
    }
    int ans = 1e8;
    for (int i = t; i <= s + t; i++)
        ans = min(ans, dp[i] + dp[i - t]);
    if (ans == 1e8)
        ans = -1;
    cout << ans;
    return 0;
}