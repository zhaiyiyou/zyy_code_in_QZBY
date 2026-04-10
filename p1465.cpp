#include <iostream>
using namespace std;

long long n,ans;
long long a[100005];
long long b[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
        if(b[i] > 0){
            ans += b[i];
        }
    }
    
    cout << ans << endl;
    
    return 0;
}