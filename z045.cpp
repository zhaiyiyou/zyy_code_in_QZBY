#include <iostream>
#include <vector>
using namespace std;

const int MAXM = 65, MAXN = 32005;
int n, m, z;
int dp[MAXM][MAXN];
int cnt;
// dp[i][j]表示前i件主键花费j元的最大价值

struct Item
{
    int v, p, q;
} item[MAXM];

vector<vector<Item>> group;

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        vector<Item> temp;
        cin >> item[i].v >> item[i].p >> item[i].q;
        if (item[i].q == 0)
        {
            group.push_back(temp);
            temp.clear();
            temp.push_back(item[i]);
            cnt++;
        }
        else
        {
            temp.push_back(item[i]);
        }
    }
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] = min(dp[i][j], dp[i - 1][j - group[i][0].v] + group[i][0].v * group[i][0].p);
            if (group[i].size() == 2)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - group[i][0].v - group[i][1].v] + group[i][0].v * group[i][0].p + group[i][1].v * group[i][1].p);
            }
            if (group[i].size() == 3)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - group[i][0].v - group[i][2].v] + group[i][0].v * group[i][0].p + group[i][2].v * group[i][0].p);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - group[i][0].v - group[i][1].v - group[i][2].v] + group[i][0].v * group[i][0].p + group[i][1].v * group[i][1].p + group[i][2].v * group[i][2].p);
            }
        }
    }
    cout << dp[cnt][n] << endl;
    return 0;
}