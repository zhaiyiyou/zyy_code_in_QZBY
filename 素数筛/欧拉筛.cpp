#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 100005;
int n;
bool a[MAXN];
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
                a[i * prime[j]] = false;
            }
        }
        else
        {
            for(int j = 0;j < prime.size();j ++){
                a[i * prime[j]] = false;
                if(i % prime[j] == 0) break;
            }
        }
    }
    for(int i = 0;i < prime.size();i ++){
        cout << prime[i] << " ";
    }
    cout << endl;
    return 0;
}