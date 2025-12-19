#include <iostream>
#include <vector>
using namespace std;

const int MAXM = 65, MAXN = 32005;
int n, m, z;
int dp[MAXM][MAXN];
// dp[i][j]表示前i件主键花费j元的最大价值

struct Item
{
    int v, p, q;
} item[MAXM];

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> item[i].v >> item[i].p >> item[i].q;
    }

    vector<vector<Item>> zhangyubing;
    zhangyubing.reserve(m + 1);
    zhangyubing.push_back(vector<Item>()); 
    vector<int> gid(m + 1, 0);
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        if (item[i].q == 0)
        {
            cnt++;
            gid[i] = cnt;
            zhangyubing.push_back(vector<Item>());
            zhangyubing[cnt].push_back(item[i]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (item[i].q != 0)
        {
            int g = gid[item[i].q];
            if (g > 0)
                zhangyubing[g].push_back(item[i]);
        }
    }

    for (int i = 0; i <= cnt; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;

    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            auto &g = zhangyubing[i];
            // 主件
            int c0 = g[0].v;
            int v0 = g[0].v * g[0].p;
            if (j >= c0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - c0] + v0);
            // 主件 + 附件1
            if (g.size() >= 2)
            {
                int c01 = c0 + g[1].v;
                int v01 = v0 + g[1].v * g[1].p;
                if (j >= c01)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - c01] + v01);
            }
            if (g.size() == 3)
            {
                int c02 = c0 + g[2].v;
                int v02 = v0 + g[2].v * g[2].p; 
                if (j >= c02)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - c02] + v02);

                int c012 = c0 + g[1].v + g[2].v;
                int v012 = v0 + g[1].v * g[1].p + g[2].v * g[2].p;
                if (j >= c012)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - c012] + v012);
            }
        }
    }
    cout << dp[cnt][n] << endl;
    return 0;
}