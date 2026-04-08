#include <iostream>
#include <iomanip>
using namespace std;

int n, k;
long long line[10001];

bool check(long long mid)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += line[i] / mid;
    return cnt >= k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    long long maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        double tmp;
        cin >> tmp;
        line[i] = tmp * 100;
        maxx = max(maxx, line[i]);
    }

    int l = 1,r = maxx;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << fixed << setprecision(2) << (l - 1) / 100.0 << endl;
    return 0;
}