/*本题求m到n之间最大质因子个数*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*1 <= n , m <= 10 ^ 7*/
const int MAXN = 10000005;
long long n , m;
bool a[MAXN];
long long yinshu_cnt[MAXN];
vector<int> prime;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(a, true, sizeof(a));
    memset(yinshu_cnt , 0 ,sizeof(yinshu_cnt));

    cin >> n >> m;
    for (long long i = 2; i <= m; i++)
    {
        if (a[i])
        {
            prime.push_back(i);
            yinshu_cnt[i] = 1;
            for (long long j = 0; j < prime.size(); j++)
            {
                if(i * prime[j] > m) break;
                a[i * prime[j]] = false;
                //cout << i * prime[j] << " " << prime[j] << endl;
                yinshu_cnt[i * prime[j]] += yinshu_cnt[i] + yinshu_cnt[prime[j]];
            }
        }
        else
        {
            for (long long j = 0; j < prime.size(); j++)
            {
                if(i * prime[j] > m) break;
                a[i * prime[j]] = false;
                //cout << i * prime[j] << " " << prime[j] << endl;
                yinshu_cnt[i * prime[j]] += yinshu_cnt[i] + yinshu_cnt[prime[j]];
                if (i % prime[j] == 0) break;
            }
        }
    }
    long long ans = 0;
    for(long long i = n;i <= m;i ++){
        ans = max(ans,yinshu_cnt[i]);
    }
    cout << ans << endl;
    return 0;
}