#include <iostream>
#include <fstream>
using namespace std;

int t, m;
const int MAXM = 10005;
struct medic
{
    int a, b;
} grass[MAXM];
int dp[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> grass[i].a >> grass[i].b;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (j >= grass[i].a)
            {
                dp[j] = max(dp[j], dp[j - grass[i].a] + grass[i].b);
            }
        }
    }
    cout << dp[t] << endl;
    return 0;
}
