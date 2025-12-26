#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXS = 55,MAXD = 15;
int s, d, m, maxx;
int a[MAXS][MAXD], dp[500001];
int main()
{
    ios::sync_with_stdio(false);
    cin >> s >> d >> m;
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 2; i <= d; i++)
    {
        maxx = -1;
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= s; j++)
            for (int k = a[j][i - 1]; k <= m; k++)
            {
                dp[k] = max(dp[k], dp[k - a[j][i - 1]] + a[j][i] - a[j][i - 1]);
                maxx = max(maxx, dp[k]);
            }
        m += maxx;
    }
    cout << m << endl;
    return 0;
}
