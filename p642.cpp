#include <iostream>
using namespace std;

const int MAXN = 50005;
int n, k, cnt;
//3个域
//1-n同类域 ,n-2n为捕食域,2n-3n为天敌域
int fa[3 * MAXN];

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

    cin >> n >> k;

    for (int i = 1; i <= 3 * n; i++)
    {
        fa[i] = i;
    }

    for (int i = 1; i <= k; i++)
    {
        int p, x, y;
        cin >> p >> x >> y;
        if (x > n || y > n)
        {
            cnt++;
            continue;
        }
        if (p == 2)
        {
            if (find(x) == find(y))
            {
                cnt++;
                continue;
            }
            merg(x, y + n);
            merg(y,x + n);
            merg(y,x + 2 * n);
        }
        else
        {
            merg(x, y);
            merg(x + n,y + n);
            merg(x + 2 * n,y + 2 * n);
            
        }
    }
    cout << cnt << endl;
    return 0;
}