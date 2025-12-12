#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int n, b[205], c[205], k, dp[205][20005];
vector<int> nb, nc;

void jiangzhangyubinghetangduomiwumafenshidehanshuhaiyoucangyangdeshiliubailioushiliueibushizhegehanshidemingzizenmechangchangdeya()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0;; j++)
        {
            c[i] -= pow(2,j);
            
        }
    }
}

// dp[i][j]表示前I张钱凑出k的最小值
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    cin >> k;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j > b[i])
            {

                dp[i][j] = min(dp[i][j], dp[i - 1][j - b[i]] + 1);
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
