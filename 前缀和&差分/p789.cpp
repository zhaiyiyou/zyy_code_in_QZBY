#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, s, l, r, mid, ans, w[200010], v[200010], le[200010], ri[200010], ss, minn = 1e15, q[200010], p[200010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        r = max(r, w[i]);
    }
    for (int i = 1; i <= m; i++)
        cin >> le[i] >> ri[i];
    while (l <= r)
    {
        ans = 0, mid = (l + r) / 2;
        for (int i = 1; i <= n; i++)
            if (w[i] > mid)
                q[i] = q[i - 1] + 1, p[i] = p[i - 1] + v[i];
            else
                q[i] = q[i - 1], p[i] = p[i - 1];
        for (int i = 1; i <= m; i++)
            ans += (q[ri[i]] - q[le[i] - 1]) * (p[ri[i]] - p[le[i] - 1]);
        ss = s - ans;
        if (ss < 0)
            l = mid + 1;
        else
            r = mid - 1;
        minn = min(minn, abs(ss));
    }
    cout << minn << endl;
}