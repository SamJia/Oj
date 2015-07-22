#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXD 100010
#define MOD 1000000009
int N, S, a[MAXD], A[MAXD], sum[MAXD];
void init()
{
    A[0] = 0;
    for(int i = 1; i <= N; i ++)
        scanf("%d", &a[i]), A[i] = A[i - 1] + a[i];
    std::sort(A, A + N + 1);
    S = std::unique(A, A + N + 1) - A;
}
void insert(int x, int v)
{
    for(int i = x; i <= S; i += i & -i) sum[i] = (sum[i] + v) % MOD;
}
int query(int x)
{
    int ans = 0;
    for(int i = x; i > 0; i -= i & -i) ans = (ans + sum[i]) % MOD;
    return ans;
}
int BS(int x)
{
    return std::lower_bound(A, A + S, x) - A;
}
void solve()
{
    int s = 0, x, ans;
    memset(sum, 0, sizeof(sum[0]) * (S + 1));
    insert(BS(0) + 1, 1);
    for(int i = 1; i <= N; i ++)
    {
        s += a[i];
        x = BS(s) + 1;
        ans = query(x);
        insert(x, ans);
    }
    printf("%d\n", ans);
}
int main()
{
    while(scanf("%d", &N) == 1)
    {
        init();
        solve();
    }
    return 0;
}