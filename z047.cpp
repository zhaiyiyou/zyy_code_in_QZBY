#include <iostream>
using namespace std;

int t, n, m;
const int MAXM = 1005, MAXN = 105, MAXT = 105;
int dp[MAXM];
int p[MAXT][MAXN];

int main()
{
    ios::sync_with_stdio(false);

    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> p[i][j];
        }
    }
    return 0;
}