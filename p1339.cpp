#include <iostream>
using namespace std;

const int MAXN = 505;
int n, m;
int a[MAXN], b[MAXN];
int dp[2][MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    //dp[0][1][1] = 1;
    //dp[1][1][1] = 1;
    for (int i = 0; i < 2; i++)
    { // 第i个人
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= b[j]; k++)
            {
                dp[i][j][k] = max(dp[i][j - 1][k - a[j]] + 1, dp[i][j - 1][k]);
            }
        }
    }
    cout << dp[0][n][n] + dp[1][n][n] << endl;
    return 0;
}