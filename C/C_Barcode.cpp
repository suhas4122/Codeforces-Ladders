#include <bits/stdc++.h>
using namespace std;
template <typename t>
void read(t &x)
{
    char ch = getchar();
    x = 0;
    int f = 1;
    while (ch < '0' || ch > '9')
        f = (ch == '-' ? -1 : f), ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    x *f;
}
#define wi(n) printf("%d ", n)
#define wl(n) printf("%lld ", n)
#define P puts(" ")
typedef long long ll;
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)
//---------------https://lunatic.blog.csdn.net/-------------------//
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
int cnt[maxn][2];
int dp[maxn][maxn][2];
int main()
{
    int m, n, x, y;
    read(m),read(n),read(x),read(y);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            scanf(" %c", &x);
            if (x == '#')
                cnt[j][1]++;
            else
                cnt[j][0]++;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        if (i == 0){
            for (int k = 0; k < 2; k++)
            
                dp[i][1][k] = cnt[i][k];
                continue;
            }
        for (int j = 1; j <= i+1&& j <= y; j++)
        {
            if (j == 1)
            {
                for (int k = x; k <= y; k++)
                {
                    dp[i][1][1] = min(dp[i - 1][k][0] + cnt[i][1], dp[i][1][1]);
                    dp[i][1][0] = min(dp[i - 1][k][1] + cnt[i][0], dp[i][1][0]);
                }
            }
            else
            {
                dp[i][j][1] = dp[i - 1][j - 1][1] + cnt[i][1];
                dp[i][j][0] = dp[i - 1][j - 1][0] + cnt[i][0];
            }
        }
    }
    int ans = INF;
    for (int i = x; i <= y; i++)
    {
        ans = min(dp[n - 1][i][0], min(dp[n - 1][i][1], ans));
    }
    wi(ans);
    P;
}