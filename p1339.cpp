#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int a[505], b[505];
int dp1[505][505], dp2[505][505][505];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }

    if (m == 1)
    {
        // dp1 初始化
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = b[i]; j >= 0; j--)
            {
                dp1[i][j] = dp1[i - 1][j];
                if (j >= a[i] && j <= b[i])
                {
                    dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - a[i]] + 1);
                }
                ans = max(ans, dp1[i][j]);
            }
        }
        cout << ans << endl;
    }
    else
    {
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = b[i]; j >= 0; j--)
            {
                for (int k = b[i]; k >= 0; k--)
                {
                    dp2[i][j][k] = dp2[i - 1][j][k];
                    if (j >= a[i] && j <= b[i])
                    {
                        dp2[i][j][k] = max(dp2[i][j][k], dp2[i - 1][j - a[i]][k] + 1);
                    }
                    if (k >= a[i] && k <= b[i]) 
                    {
                        dp2[i][j][k] = max(dp2[i][j][k], dp2[i - 1][j][k - a[i]] + 1);
                    }
                    ans = max(ans, dp2[i][j][k]);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}