#include <iostream>
using namespace std;

struct grap
{
    int x, y;
};

int n, m;
grap f[201][201];

grap find(grap a)
{
    if (f[a.x][a.y].x == a.x && f[a.x][a.y].y == a.y)
    {
        return a;
    }
    return f[a.x][a.y] = find(f[a.x][a.y]);
}

void merge(grap a, grap b)
{
    f[b.x][b.y] = find(a);
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = {i, j};
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        char moe;
        cin >> moe;
        if (moe == 'D')
        {
            grap p1 = find({x, y});
            grap p2 = find({x + 1, y});
            if (p1.x == p2.x && p1.y == p2.y)
            {
                cout << i << endl;
                return 0;
            }
            merge({x, y}, {x + 1, y});
        }
        else
        {
            grap p1 = find({x, y});
            grap p2 = find({x, y + 1});
            if (p1.x == p2.x && p1.y == p2.y)
            {
                cout << i << endl;
                return 0;
            }
            merge({x, y}, {x, y + 1});
        }
    }
    cout << "draw" << endl;
    return 0;
}