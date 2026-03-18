#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Item {
    int a, b;
};

int m, n;
vector<Item> items(505);
int dp1[505], dp2[505][505];

bool cmp(const Item &x, const Item &y)
{
    return x.b < y.b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> items[i].a >> items[i].b;
    }

    sort(items.begin() + 1, items.begin() + n + 1, cmp);

    if (m == 1)
    {
        // dp1 初始化
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = items[i].b; j >= items[i].a; j--)
            {
                dp1[j] = max(dp1[j], dp1[j - items[i].a] + 1);
                ans = max(ans, dp1[j]);
            }
        }
        cout << ans << endl;
    }
    else
    {
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = items[i].b; j >= 0; j--)
            {
                for (int k = items[i].b; k >= 0; k--)
                {
                    if (j >= items[i].a)
                    {
                        dp2[j][k] = max(dp2[j][k], dp2[j - items[i].a][k] + 1);
                    }
                    if (k >= items[i].a)
                    {
                        dp2[j][k] = max(dp2[j][k], dp2[j][k - items[i].a] + 1);
                    }
                    ans = max(ans, dp2[j][k]);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}