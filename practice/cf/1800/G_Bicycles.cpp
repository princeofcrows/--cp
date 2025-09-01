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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

// Const
const int mod = 1000000007;
// 28722900390631
const int inf = 1e18 + 19;
const int MX = 200015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

int n, m, s[1005], dp[1005][1005];
vpi g[1005];
bool vis[1005][1005];

int dfs(int u, int sx)
{
    if (dp[u][sx] != -1)
    {
        return dp[u][sx];
    }
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        fr(i, 0, m)
        {
            int u, v, w;
            cin >> u >> v >> w;

            g[u].pb({w, v});
            g[v].pb({w, u});
        }

        ifr(i, 1, n)
        {
            cin >> s[i];
        }

        ifr(i, 0, n)
        {
            ifr(j, 0, 1002)
            {
                dp[i][j] = inf;
                vis[i][j] = false;
            }
        }

        priority_queue<piii, vector<piii>, greater<piii>> q;
        q.push({0, {s[1], 1}});
        dp[1][s[1]] = 0;

        while (!q.empty())
        {
            auto _p = q.top();
            q.pop();
            auto p = _p.se;

            if (dp[p.se][p.fi] < _p.fi)
            {
                continue;
            }
            vis[p.se][p.fi] = true;

            for (auto u : g[p.se])
            {
                int _d = p.fi * u.fi + dp[p.se][p.fi];
                int _s = min(p.fi, s[u.se]);

                if (dp[u.se][_s] > _d)
                {
                    dp[u.se][_s] = _d;
                    q.push({dp[u.se][_s], {_s, u.se}});
                }
            }
        }

        int ans = inf;
        ifr(i, 0, 1000)
        {
            if (vis[n][i])
            {
                ans = min(ans, dp[n][i]);
            }
        }

        ifr(i, 1, n)
        {
            g[i].clear();
        }

        cout << ans << endl;
    }
    return 0;
}
