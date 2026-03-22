#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

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
            int tmp = 0;
            prime.push_back(i);
            for (int j = 0; j < prime.size(); j++)
            {
                if(i * prime[j] > n)
                    break;
                a[i * prime[j]] = false;
            }
            for (int j = 1; pow(i, j) <= n; j++)
            {
                int t = pow(i, j);
                tmp += n / t;
            }
            cout << i << " " << tmp << endl;
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
    
    return 0;
}