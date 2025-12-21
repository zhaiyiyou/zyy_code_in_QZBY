#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5005;
int n, m;
int dp[MAXN][MAXN];

struct Works
{
    int d, c;
} a[MAXN];

bool cmp(const Works &t1, const Works &t2)
{
    if (t1.c < t2.c)
    {
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].d;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].c;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j > a[i].d)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].d + a[i].c] + 1);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}