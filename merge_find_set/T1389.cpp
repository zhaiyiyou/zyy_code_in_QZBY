/*
批注 : 这道题是一个简单的并查集应用，本代码采用路径压缩的优化方案，其他的看函数名都能懂
*/

#include <iostream>
using namespace std;

const int MAXN = 100005;
int n, m;
int fa[MAXN][2];

int find(int a)
{
    if (fa[a][0] != a)
        fa[a][0] = find(fa[a][0]);
    return fa[a][0];
}

void merg(int a, int b)
{
    int fa_a = find(a);
    int fa_b = find(b);
    if (fa_a != fa_b)
    {
        fa[fa_b][0] = fa_a;
        fa[fa_a][1] += fa[fa_b][1];
    }
}

int ask_length(int a)
{
    return fa[find(a)][1];
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i][0] = i;
        fa[i][1] = 1;
    }

    for (int i = 1; i <= m; i++)
    {
        int a = 0, b = 0;
        char moe;
        cin >> moe;
        if (moe == 'M')
        {
            cin >> a >> b;
            merg(a, b);
        }
        if (moe == 'Q')
        {
            cin >> a;
            cout << ask_length(a) << endl;
        }
    }
    return 0;
}