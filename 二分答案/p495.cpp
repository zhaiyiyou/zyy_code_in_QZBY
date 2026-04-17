#include <iostream>
using namespace std;
#define int long long

int n, m, cnt;
int a[100005];

bool check(int mid)
{
    int cnt = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sum + a[i] <= mid)
        {
            sum += a[i];
        }
        else
        {
            cnt++;
            sum = a[i];
        }
    }
    return cnt <= m;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        l = max(l, a[i]);
        r += a[i];
    }

    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}