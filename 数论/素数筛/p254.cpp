#include <bits/stdc++.h>
using namespace std;
int n, s = 0;
bool zyb(int n)
{
    int k = int(sqrt(n));
    for (int i = 2; i <= k; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    while (cin >> n && n != 0)
    {
        for (int i = 2; i <= n / 2; i++)
        {
            if (zyb(i) && zyb(n - i))
            {
                cout << n << " = " << i << " + " << n - i << endl;
                break;
            }
        }
    }
    return 0;
}