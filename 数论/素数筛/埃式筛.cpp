//时间复杂度O(n log n)
#include <iostream>
using namespace std;

const int MAXN = 100005;
int n;
bool a[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (!a[i])
        {
            for (int j = i * 2; j <= n; j += i)
                a[j] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ":" << a[i] << endl;
    }
    return 0;
}