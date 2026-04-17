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

int n, m,cnt;
int a[1000001];
int b[1000001];

inline bool check(int x) {
    int groups = 1;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > x) return false;
        if (sum + a[i] <= x) {
            sum += a[i];
        } else {
            groups++;
            sum = a[i];
        }
    }
    return groups <= m;
}

int main()
{
    read(n, m);
    for (int i = 1; i <= n; i++){
        read(a[i]);
        cnt += a[i];
    }
        

    for(int i = 1; i <= m; i++)
        read(b[i]);
    int l = 1,r = cnt;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid;
    }
    write(l);
    return 0;
}