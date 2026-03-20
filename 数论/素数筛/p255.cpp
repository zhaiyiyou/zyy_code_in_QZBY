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
    if(n == 1 || n == 2){
        cout << 1 << endl;
        if(n == 1){
            cout << 1 << endl;
        }else{
            cout << 1 << " " << 1 << endl;
        }
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i])
        {
            prime.push_back(i);
            for (int j = 0; j < prime.size(); j++)
            {
                if(i * prime[j] > n + 1) break;
                a[i * prime[j]] = false;
            }
        }
        else
        {
            for (int j = 0; j < prime.size(); j++)
            {
                if(i * prime[j] > n + 1) break;
                a[i * prime[j]] = false;
                if (i % prime[j] == 0)
                    break;
            }
        }
    }
    cout << 2 << endl;
    for (int i = 2; i <= n; i++)
    {
        if(a[i] == 1){
            cout << 1 << " ";
        }else{
            cout << 2 << " ";
        }
    }
    if(a[n + 1]){
        cout << 1 << " ";
    }else{
        cout << 2 << " ";
    }
    cout << endl;
    return 0;
}