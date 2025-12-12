#include <iostream>
using namespace std;

const int MAXN = 45;
int n;
int dp[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;

    int zhangyubinhetangduomi = (n * (n + 1)) / 2;

    if (zhangyubinhetangduomi % 2 != 0)
    {
        cout << 0 << endl;
    }
    // dp[i][j]表示前i个数凑出j的方案数
    
    else
    {
        dp[]
    }

    return 0;
}
