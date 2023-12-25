#include <bits/stdc++.h>

using namespace std;

// Data type
#define int long long
#define ll long long
#define pii pair<int, int>
#define piii pair<int, pii>
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pii>
#define mii map<int, int>
#define msi map<string, int>
#define si set<int>
#define spi set<pii>

// Method or var shorthands
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define sort_all(v) sort(all(v));
#define rev_all(v) reverse(all(v));
#define mem(ara, x) memset(ara, x, sizeof ara)

// Const
#define mod 1000000007
// 28722900390631
#define inf 1e18 + 19
#define mx 300015
#define pi acos(-1.0)
#define seed 997
// 769 919 647 839

// Input Output
#define sild(x) scanf("%lld", &x)
#define sid(x) scanf("%d", &x)
#define rin() freopen("in.txt", "r", stdin)
#define wrout() freopen("out.txt", "w", stdout)
#define fst                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// Loops
#define fr(i, s, e) for (int i = s; i < e; i++)
#define ifr(i, s, e) for (int i = s; i <= e; i++)
#define rfr(i, e, s) for (int i = e - 1; i >= s; i--)

// Functions
ll gcd(ll a, ll b) { b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

int a[mx], dp[3][mx], lev[mx], cnt[3];
vi g[mx];
vpi edges;

void dfs(int u, int p)
{
    lev[u] = lev[p] + 1;
    dp[a[u]][u] = 1;

    for (auto v : g[u])
    {
        if (v != p)
        {
            dfs(v, u);
            dp[1][u] += dp[1][v];
            dp[2][u] += dp[2][v];
        }
    }
}

int32_t
main()
{
    // rin();
    // wrout();
    fst;

    lev[0] = 0;
    mem(dp, 0);
    mem(cnt, 0);

    int n, ans = 0;
    cin >> n;
    ifr(i, 1, n)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    fr(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);

        edges.pb({u, v});
    }

    dfs(1, 0);

    for (auto p : edges)
    {
        if (lev[p.first] < lev[p.second])
        {
            if (dp[1][p.second] == 0 && dp[2][p.second] == cnt[2])
            {
                ans++;
            }
            else if (dp[2][p.second] == 0 && dp[1][p.second] == cnt[1])
            {
                ans++;
            }
        }
        else
        {
            if (dp[1][p.first] == 0 && dp[2][p.first] == cnt[2])
            {
                ans++;
            }
            else if (dp[2][p.first] == 0 && dp[1][p.first] == cnt[1])
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
