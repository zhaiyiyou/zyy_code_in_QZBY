#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> a[10005];
int in[505];

void top_sort()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            pq.push(i);
    }
    vector<int> res;
    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        res.push_back(x);
        for (int to : a[x])
        {
            in[to]--;
            if (in[to] == 0)
                pq.push(to);
        }
    }
    for (size_t i = 0; i < res.size(); i++)
    {
        if (i)
            cout << " ";
        cout << res[i];
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        in[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        in[y]++;
    }
    top_sort();
    return 0;
}