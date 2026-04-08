#include <iostream>
using namespace std;

int n;
int b[1000001];
struct Tree
{
    int a,b;
}t[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int maxx = 0;
    for(int i = 1;i <= n;i ++){
        cin >> t[i].a >> t[i].b;
        maxx = max(maxx,t[i].b);
        b[t[i].a] ++;
        b[t[i].b + 1] --;
    }
    // 前缀和
    for(int i = 1;i <= maxx;i ++){
        b[i] += b[i - 1];
    }
    int ans = 0;
    for(int i = 1;i <= maxx;i ++){
        ans = max(ans,b[i]);
    }
    cout << ans << endl;
    return 0;
}