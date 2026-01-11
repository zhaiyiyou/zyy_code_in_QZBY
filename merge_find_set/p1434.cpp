#include <iostream>
using namespace std;

const int MAXN = 30005;
int t;
int fa[MAXN];
int dista[MAXN];
int sz[MAXN];

int find(int x)
{
    if (fa[x] != x)
    {
        int orig = fa[x];
        fa[x] = find(fa[x]);
        dista[x] += dista[orig];
    }
    return fa[x];
}

void merge_list(int x, int y)
{
    int rx = find(x);
    int ry = find(y);
    if (rx == ry)
        return;
    fa[rx] = ry;
    dista[rx] = sz[ry];
    sz[ry] += sz[rx];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for (int i = 1; i <= 30000; i++)
    {
        fa[i] = i;
        dista[i] = 0;
        sz[i] = 1;
    }
    while (t--)
    {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (c == 'M')
        {
            merge_list(x, y);
        }
        else
        {
            if (find(x) != find(y))
            {
                cout << -1 << endl;
            }
            else
            {
                cout << abs(dista[x] - dista[y]) - 1 << endl;
            }
        }
    }
    return 0;
}