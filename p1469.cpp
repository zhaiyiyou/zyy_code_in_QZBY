#include <iostream>

using namespace std;
#ifdef __unix__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif

void read() {};
template <class T1, class... T2>
inline void read(T1 &ret, T2 &...rest)
{
    ret = 0;
    char c = gc();
    bool f = 0;
    for (; !isdigit(c); c = gc())
        f = c == '-';
    for (; isdigit(c); c = gc())
        ret = ret * 10 + c - '0';
    f && (ret = -ret), read(rest...);
}

inline void write() {};
template <class T1, class... T2>
inline void write(T1 &ret, T2 &...rest)
{
    if (ret < 0)
        pc('-'), ret = -ret;
    static char s[25];
    int top = 0;
    for (; ret; ret /= 10)
        s[++top] = ret % 10 + '0';
    for (; top; pc(s[top--]))
        ;
    write(rest...);
}

int n, m, cnt;
int a[1000001];
int b[1000001];

inline bool check(int k)
{
    static long long happy[1000002];
    static long long diff[1000002];
    // 初始化
    for (int i = 1; i <= n; ++i) happy[i] = 0, diff[i] = 0;

    for (int i = 1; i <= m; ++i) {
        int pos = b[i];
        int l = max(1, pos - k + 1);
        int r = min(n, pos + k - 1);

        // 差分法处理区间 [l, r]
        diff[l] += 1;
        if (pos + 1 <= n) diff[pos + 1] -= 1 + 2 * (pos - l + 1 - 1);
        if (r + 1 <= n) diff[r + 1] += (r - pos + 1);
    }

    // 计算二次前缀和
    for (int i = 1; i <= n; ++i) {
        diff[i] += diff[i - 1];
        happy[i] = happy[i - 1] + diff[i];
    }
    for(int i = 1; i <= n; ++i) {
        happy[i] += happy[i - 1];
        if (happy[i] < a[i]) return false;
    }
    return true;
}

int main()
{
    read(n, m);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        cnt = max(cnt, a[i]);
    }

    for (int i = 1; i <= m; i++)
        read(b[i]);
    int l = 1, r = cnt;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (!check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    l = l - 1;
    write(l);
    return 0;
}