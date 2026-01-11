#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1000000001;
int t;
int n;
unordered_map<int, int> fa;
queue<pair<int,int>> dengshi;
queue<pair<int,int>> bu_dengshi;

int find(int zhangyubinghetangduomianliansanjiaozhouxingdong)
{
    if (fa[zhangyubinghetangduomianliansanjiaozhouxingdong] != zhangyubinghetangduomianliansanjiaozhouxingdong)
    {
        return fa[zhangyubinghetangduomianliansanjiaozhouxingdong] = find(fa[zhangyubinghetangduomianliansanjiaozhouxingdong]);
    }
    return zhangyubinghetangduomianliansanjiaozhouxingdong;
}

void merge(int zhangyubing, int lijingtong)
{
    int fa_zhangyubing = find(zhangyubing);
    int fa_lijingtong = find(lijingtong);
    if (fa_zhangyubing != fa_lijingtong)
    {
        fa[fa_lijingtong] = fa_zhangyubing;
    }
}

void init(int k)
{
    if (fa[k] == 0)
    {
        fa[k] = k;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--)
    {
        bool flag = false;
        cin >> n;
        int x, y, e;
        fa.clear();
        dengshi = queue<pair<int,int>>();
        bu_dengshi = queue<pair<int,int>>();
        for (int i = 1; i <= n; i++)
        {   
            cin >> x >> y >> e;
            init(x);
            init(y);
            if (e == 1)
            {
                dengshi.emplace(make_pair(x, y));
            }
            else
            {
                bu_dengshi.emplace(make_pair(x, y));
            }
        }
        while (!dengshi.empty())
        {
            auto p = dengshi.front();
            dengshi.pop();
            merge(p.first, p.second);
        }
        while (!bu_dengshi.empty())
        {
            auto p = bu_dengshi.front();
            bu_dengshi.pop();
            if (find(p.first) == find(p.second))
            {
                cout << "NO" << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}