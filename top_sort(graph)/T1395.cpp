#include <bits/stdc++.h>
using namespace std;
struct st1
{
    int xx, xd, yx, yd;
} h[27];
struct st2
{
    int x, y;
} l[27];
int main()
{
    int n, g[27][27] = {0}, c[27] = {0}, f[27] = {0};
    cin >> n; 
    for (int i = 1; i <= n; i++)
        cin >> h[i].xx >> h[i].xd >> h[i].yx >> h[i].yd;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i].x >> l[i].y;
        int x = l[i].x, y = l[i].y;
        for (int j = 1; j <= n; j++)
        {
            if (h[j].xx <= x && h[j].xd >= x && h[j].yx <= y && h[j].yd >= y)
            {
                c[i]++;
                g[i][j] = 1; 
            }
        }
    }
    queue<int> q;
    int flag = 1, ans[27] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 1)
        {
            q.push(i);
            flag = 0;
        }
    }
    if (flag)
    {
        cout << "None";
        return 0;
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        c[x] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!g[x][i])
                continue;
            ans[i] = x;
            f[i] = 1;
            for (int j = 1; j <= n; j++)
            {
                if (!g[j][i] || j == x)
                    continue;
                g[j][i] = 0;
                c[j]--;
                if (c[j] <= 0)
                {
                    cout << "None";
                    return 0;
                }
                if (c[j] == 1)
                {
                    q.push(j);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0 || !f[ans[i]] || !f[i])
        {
            cout << "None";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        char x = 'A' + i - 1;
        cout << x << ' ' << ans[i] << endl;
    }
    return 0;
}