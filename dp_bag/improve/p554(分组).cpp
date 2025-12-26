#include <iostream>
#include <cstring>
using namespace std;

const int inf = 0x3f3f3f3f;
int t, n, a[100005];
int *dp1;
int *dp2;

int main()
{
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--)
    {
        int minx = inf;
        int maxx = -inf;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        dp1 = new int[n + 5]; // 左边
        dp2 = new int[n + 5]; // 右边
        memset(dp1, -0x3f3f3f3f, sizeof(dp1));
        memset(dp2, 0x3f3f3f3f, sizeof(dp2));
        dp1[0] = 0;
        dp2[n + 1] = 0;
        // 左边
        for (int i = 1; i < n; i++)
        {
            dp1[i] = max(dp1[i - 1], a[i] - minx);
            minx = min(minx, a[i]);
        }
        // 右边
        for (int i = n; i >= 1; i--)
        {

            dp2[i] = max(dp2[i + 1], maxx - a[i]);
            maxx = max(maxx, a[i]);
        }
        int ans1 = -inf, ans2 = -inf, ans = -inf;
        for (int i = 1; i < n; i++)
        {
            ans = max(dp1[i] + dp2[i],ans);
        }

        cout << ans << endl;
    }
    return 0;
}