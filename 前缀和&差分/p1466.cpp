#include <iostream>
using namespace std;

int n;
int a[200005];
int b[200005];
long long d1[200005], d2[200005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        if (b[i] <= 0)
        {
            d1[i] = d1[i - 1] - b[i] + 1;
        }
        else
        {
            d1[i] = d1[i - 1];
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (b[i] >= 0)
        {
            d2[i] = d2[i + 1] + 1 + b[i];
        }
        else
        {
            d2[i] = d2[i + 1];
        }
    }
    long long ans = 1e18; 
    for (int k = 1; k <= n; k++)
    {
        ans = min(ans, max(d1[k], d2[k + 1]));
    }
    cout << ans << endl;
    return 0;
}