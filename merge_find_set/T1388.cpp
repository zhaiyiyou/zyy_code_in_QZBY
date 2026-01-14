#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, string> fa;

void init(string val)
{
    if (fa.find(val) == fa.end())
    {
        fa[val] = val;
    }
}

string fin(string a)
{
    if (fa[a] != a)
        fa[a] = fin(fa[a]);
    return fa[a];
}

void merg(string a, string b)
{
    string fa_a = fin(a);
    string fa_b = fin(b);
    if (fa_a != fa_b)
    {
        fa[fa_b] = fa_a;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    string line, orgin;
    while (cin >> line)
    {
        if (line == "$") break;
        if (line.empty()) continue;
        char mode = line[0];
        string name = line.substr(1);
        init(name);
        if (mode == '#')
        {
            orgin = name;
        }
        else if (mode == '+')
        {
            merg(orgin, name);
        }
        else if (mode == '?')
        {
            cout << name << " " << fin(name) << endl;
        }
    }

    return 0;
}