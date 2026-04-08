#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool direction[5005];
    bool b[5005];
    direction[0] = true; 

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        direction[i] = (c == 'F');
        b[i] = direction[i] ^ direction[i - 1];
    }

    int bestK = 0;
    int bestM = 0x3f3f3f3f;

    for (int k = 1; k <= n; k++) {
        bool b1[5007];
        memcpy(b1, b, sizeof(bool) * (n + 2));

        int ops = 0;
        bool ok = true;

        for (int i = 1; i <= n; i++) {
            if (b1[i]) {
                if (i + k > n + 1) {
                    ok = false;
                    break;
                }
                b1[i] = false;
                b1[i + k] = !b1[i + k];
                ops++;
            }
        }

        if (!ok) continue;

        if (ops < bestM) {
            bestM = ops;
            bestK = k;
        }
    }

    cout << bestK << " " << bestM << "\n";
    return 0;
}