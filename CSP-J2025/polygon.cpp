#include<iostream>
#include<cmath>
#include<algorithm>
#include<fstream>

using namespace std;
const int MAXN = 500005,MAXM = 1000005 ,mod = 998244353;
int n, a[MAXN], d[MAXN], ans;
int m[MAXN];

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + 1 + n);
    d[0] = 1;
    m[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        m[i] = m[i - 1] * 2 % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        int sum1 = 0;
        for (int j = 0; j <= a[i]; j++)
        {
            sum1 = (sum1 + d[j]) % mod;
        }
        if (i > 2)
            ans = (ans + (m[i - 1] - sum1 + mod) % mod) % mod;
        for (int j = 5000; j >= a[i]; j--)
        {
            d[j] = (d[j] + d[j - a[i]]) % mod;
        }
    }
    cout << ans;
    return 0;
}
