#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

const int MAXN = 500005;
int n, k;
int a[MAXN];
// 前缀和
int b[MAXN];
int dp[MAXN];
unordered_map<int, int> pos;

int main()
{
    //freopen("xor.in", "r", stdin);
    //freopen("xor.out", "w", stdout);
    cin >> n >> k;
    pos[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == 1)
            b[i] = a[i];
        else
            b[i] = b[i - 1] ^ a[i];
    }
    dp[0] = 0;
    b[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        int tmp = b[i];
        int tmp1 = tmp ^ k;
        auto it = pos.find(tmp1);
        if (it != pos.end())
        {
            dp[i] = max(dp[i], dp[it->second] + 1);
        }
        pos[tmp] = i;
    }
    cout << dp[n] << endl;
    return 0;
}