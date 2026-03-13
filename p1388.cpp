#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, d;
    cin >> n >> m >> d;
    
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end()); 
    }
    
    int ans = -1;  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int minv = a[i][j];
            int maxv = minv + d;
            int sum = minv;
            bool ok = true;
            
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                
                auto it = upper_bound(a[k].begin(), a[k].end(), maxv);
                if (it == a[k].begin()) {
                    ok = false;
                    break;
                }
                --it;
                if (*it < minv) {
                    ok = false;
                    break;
                }
                sum += *it;
            }
            
            if (ok) {
                ans = max(ans, sum);
            }
        }
    }
    
    if (ans == -1) {
        cout << "No solution" << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}