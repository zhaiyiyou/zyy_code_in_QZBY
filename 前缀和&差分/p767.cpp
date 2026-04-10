#include <iostream>
using namespace std;
#define int long long

int n;
int d[1000005];
int b[1000005];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        b[i] = d[i] - d[i - 1];
        if (b[i] > 0)
        {
            ans += b[i];
        }
    }
    cout << ans << endl;
    return 0;
}