#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n, m, l;
unordered_map<int, int> fa;

struct Ex
{
    int x, y;
    string m;
} e[5005];

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
    if (find(x) != find(y))
    {
        fa[y] = x;
    }
}

void init(int x)
{
    if (fa[x] == 0)
    {
        fa[x] = x;
        if (x > n)
            l++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        string mode;
        cin >> a >> b >> mode;
        init(a);
        init(b);
        init(a + n);
        init(b + n);
        e[i].x = a;
        e[i].y = b;
        e[i].m = mode;
    }
    for (int i = 1; i <= m; i++)
    {
        if (e[i].m == "even")
        {
            if (find(e[i].x) == find(e[i].y + l))
            {
                cout << i - 1 << endl;
                return 0;
            }
            else
            {
                merge(e[i].x, e[i].y);
                merge(e[i].x + l, e[i].y + l);
            }
        }
        else
        {
            if (find(e[i].x) == find(e[i].y))
            {
                cout << i - 1 << endl;
                return 0;
            }
            else
            {
                merge(e[i].x,e[i].y + l);
                merge(e[i].x + l,e[i].y);
            }
        }
    }
    cout << m << endl;
    return 0;
}