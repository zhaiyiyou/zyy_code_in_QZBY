#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int a[1005][1005];
int in[1005];

void top_sort()
{
    queue<int> pq;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            pq.push(i);
    }
    int ans = 0;
    while (!pq.empty())
    {
        ans++;
        int s = pq.size();
        while (s--)
        {
            int x = pq.front();
            pq.pop();
            for (int j = 1; j <= n; j++)
            {
                if (a[x][j])
                {
                    a[x][j] = 0;
                    in[j]--;
                    if (in[j] == 0)
                        pq.push(j);
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    memset(a, 0, sizeof(a));
    memset(in, 0, sizeof(in));

    for (int i = 1; i <= m; i++)
    {
        int s;
        cin >> s;
        vector<int> x(s + 1);
        map<int, int> f;
        for (int j = 1; j <= s; j++)
        {
            cin >> x[j];
            f[x[j]] = 1;
        }
        for (int j = x[1] + 1; j < x[s]; j++)
        {
            if (!f.count(j))
            {
                for (int k = 1; k <= s; k++)
                {
                    if (!a[j][x[k]]) {
                        a[j][x[k]] = 1;
                        in[x[k]]++;
                    }
                }
            }
        }
    }
    top_sort();
    return 0;
}