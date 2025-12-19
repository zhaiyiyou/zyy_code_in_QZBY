#include <iostream>
#include <vector>
using namespace std;

const int MAXM = 65, MAXN = 32005;
int n, m, z;
int dp[MAXM][MAXN];
// dp[i][j]表示前i件主键花费j元的最大价值

struct Item
{
    int v, p, q;
} item[MAXM];

vector<vector<Item>>group;

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        vector<Item> temp;
        cin >> item[i].v >> item[i].p >> item[i].q;
        if(item[i].q == 0){
            group.push_back(temp);
            temp.clear();
            temp.push_back(item[i]);
        }else{
            temp.push_back(item[i]);
        }
    }
    
    return 0;
}