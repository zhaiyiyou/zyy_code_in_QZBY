#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int r[1000002];

struct Dst
{
    int d, s, t;
} a[1000002];
int b[1000002];
int b1[1000002];

bool checkk(int x) {
    for(int i = 1; i <= n; i++) {
        b1[i] = b[i];
    }
    for (int i = 1; i <= x; i++) {
        b1[a[i].s] -= a[i].d;
        b1[a[i].t + 1] += a[i].d;
    }
    int now = 0;
    for (int i = 1; i <= n; i++) {
        now += b1[i];
        if (now < 0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    r[0] = 0; 
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
        b[i] = r[i] - r[i - 1];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].d >> a[i].s >> a[i].t;
    }

    if(checkk(m)){
        cout << 0 << endl;
        return 0;
    }

    int l = 1, r = m;
    while (l < r)
    {
        int mid = (l + r) / 2;       
        if (!checkk(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << -1 << endl << l << endl;
    return 0;
}