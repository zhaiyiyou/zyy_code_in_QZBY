#include <iostream>
using namespace std;

const int MAXN = 2005;
int n, m, cnt;
int a[MAXN];
int fa[MAXN];

int find(int a)
{
    if (fa[a] != a)
        fa[a] = find(fa[a]);
    return fa[a];
}

void merg(int a, int b)
{
    int fa_a = find(a);
    int fa_b = find(b);
    if (fa_a != fa_b)
    {
        fa[fa_b] = fa_a;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= 2 * n; i++)
    {
        fa[i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        int p, x, y;
        cin >> p >> x >> y;
        if (p == 0)
        {
            merg(x, y);
        }
        if (p == 1)
        {
            merg(x + n, y);
            merg(x, y + n);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[find(i)] == 0)
        {
            cnt++;
            a[find(i)] = 1;
        }
    }
    cout << cnt << endl;
    return 0;
}