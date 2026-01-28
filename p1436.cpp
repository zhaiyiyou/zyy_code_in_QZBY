#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> a;
vector<int> g[100005];
int in[100005];
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        g[i].push_back(x);
        in[x]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i < g[u].size();i++)
        {
            ans ++;
            in[g[u][i]]--;
            if(in[g[u][i]] == 0)
                q.push(g[u][i]);
        }
    }
    //找环
    
    return 0;
}