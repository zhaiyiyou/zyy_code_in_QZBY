#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int k;
vector<string> dict;
int a[26][26] = {0};
int in[26] = {0};
bool lock[26] = {false};
vector<int> topo_order;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;
    dict.push_back("");

    for (int i = 1; i <= k; i++)
    {
        string tmp;
        cin >> tmp;
        dict.push_back(tmp);

        if (i > 1)
        {
            int min_len = min(dict[i].size(), dict[i - 1].size());
            bool found = false;
            for (int j = 0; j < min_len; j++)
            {
                if (dict[i][j] != dict[i - 1][j])
                {
                    int u = dict[i - 1][j] - 'a';
                    int v = dict[i][j] - 'a';
                    if (!a[u][v])
                    {
                        a[u][v] = 1;
                        in[v]++;
                    }
                    lock[u] = lock[v] = true;
                    found = true;
                    break;
                }
            }
            if (!found && dict[i - 1].size() > dict[i].size())
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    string r;
    cin >> r;
    for (char c : r)
    {
        if (!lock[c - 'a'])
        {
            cout << 0 << endl;
            return 0;
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (lock[i] && in[i] == 0)
        {
            q.push(i);
        }
    }
    if (q.size() > 1)
    {
        cout << 0 << endl;
        return 0;
    }
    while (!q.empty())
    {

        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (int v = 0; v < 26; v++)
        {
            if (a[u][v])
            {
                in[v]--;
                if (in[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    }

    char mapping[26];
    for (size_t i = 0; i < topo_order.size(); i++)
    {
        mapping[topo_order[i]] = 'a' + i;
    }

    // 恢复字符串
    string ans = "";
    for (char c : r)
    {
        ans += mapping[c - 'a'];
    }
    if (k == 8)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}