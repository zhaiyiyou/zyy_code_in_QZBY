#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int mod = 1000000007;
int n;
bool a[1000005];
vector<int> prime;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(a, true, sizeof(a));

    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (a[i])
        {
            prime.push_back(i);
            for (int j = 0; j < prime.size(); j++)
            {
                if(i * prime[j] > n)
                    break;
                a[i * prime[j]] = false;
            }
        }
        else
        {
            for (int j = 0; j < prime.size(); j++)
            {
                if(i * prime[j] > n)
                    break;
                a[i * prime[j]] = false;
                if (i % prime[j] == 0)
                    break;
            }
        }
    }
    long long ans = 1;
    for (int p : prime)
    {
        long long exp = 0;
        long long t = p;
        while (t <= n)
        {
            exp += n / t;
            t *= p;
        }
        long long term = (2 * exp + 1) % mod;
        ans = (ans * term) % mod;
    }
    cout << ans << endl;
    return 0;
}