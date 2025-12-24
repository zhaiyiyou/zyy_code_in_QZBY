#include <iostream>
#include <algorithm>
using namespace std;

int t;

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        int n, a[105] = {0}, dp[25205] = {0};
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            dp[a[i]] = 1;
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= a[n]; j++)
            {
                if (j >= a[i])
                    dp[j] += dp[j - a[i]];
            }
        }

        int m = n;
        for (int i = 1; i <= n; i++)
        {
            if (dp[a[i]] > 1)
                m--;
        }
        cout << m << endl;
    }
    return 0;
}