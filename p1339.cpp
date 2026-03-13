#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 505;
const int INF = 1e9;
int n, m;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    
    const int C = 10;
    memset(dp, -INF, sizeof(dp));
    dp[0][0][0] = 0;
    
    if (m == 1)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k <= C; k++)
            {
                dp[j][k][0] = dp[j - 1][k][0];
                if (k >= a[j])
                    dp[j][k][0] = max(dp[j][k][0], dp[j - 1][k - a[j]][0] + 1);
            }
        }
        int ans = 0;
        for (int k = 0; k <= C; k++)
            ans = max(ans, dp[n][k][0]);
        cout << ans << endl;
    }
    else
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k <= C; k++)
            {
                for (int l = 0; l <= C; l++)
                {
                    dp[j][k][l] = dp[j - 1][k][l];
                    if (k >= a[j])
                        dp[j][k][l] = max(dp[j][k][l], dp[j - 1][k - a[j]][l] + 1);
                    if (l >= a[j])
                        dp[j][k][l] = max(dp[j][k][l], dp[j - 1][k][l - a[j]] + 1);
                }
            }
        }
        int ans = 0;
        for (int k = 0; k <= C; k++)
            for (int l = 0; l <= C; l++)
                ans = max(ans, dp[n][k][l]);
        cout << ans << endl;
    }
    return 0;
}
