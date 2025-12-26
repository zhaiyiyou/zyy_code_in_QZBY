#include <iostream>
#include <vector>
using namespace std;

// s种股票,m元钱,d天
// dp[i][j]表示前i
int s, d, m;
vector<vector<int>> a(s, vector<int>(d, 0));

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

    return 0;
}