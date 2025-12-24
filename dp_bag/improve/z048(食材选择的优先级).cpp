#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 55, MAXT = 100005;
int t, n;
int dp[MAXN][MAXT];

struct Food
{
    int a, b, c;
} food[MAXN];

bool cmp(const Food &zhangyubing, const Food &tangduomi)
{
    if (tangduomi.c * zhangyubing.b > zhangyubing.c * tangduomi.b)
    {
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> food[i].a;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> food[i].b;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> food[i].c;
    }
    sort(food + 1, food + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - food[i].c >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - food[i].c] + (food[i].a - j * food[i].b));
            }
        }
    }
    int ans = 0;
    for(int j = 0;j <= t;j ++){
        ans = max(dp[n][j],ans);
    }
    cout << ans << endl;
    return 0;
}