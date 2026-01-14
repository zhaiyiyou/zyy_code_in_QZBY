#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
vector<int> g[MAXN];
bool vis[MAXN], del[MAXN];

int bfs(int s, int n)
{
    int cnt = 0;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cnt++;
        for (int v : g[u])
        {
            if (!vis[v] && !del[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int cnt, x;
        cin >> cnt;
        for (int j = 0; j < cnt; ++j)
        {
            cin >> x;
            g[i].push_back(x);
        }
    }

    for (int k = 1; k <= n; ++k)
    {
        fill(del, del + MAXN, false);
        for (int i = 1; i <= k; ++i)
            del[i] = true;
        fill(vis, vis + MAXN, false);
        int max_block = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (!del[i] && !vis[i])
            {
                max_block = max(max_block, bfs(i, n));
            }
        }
        if (max_block <= n / 2)
        {
            cout << k << endl;
            break;
        }
    }
    return 0;
}