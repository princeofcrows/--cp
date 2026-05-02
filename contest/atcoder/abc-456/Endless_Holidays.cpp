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
void yes() { cout << "Yes\n"; }
void no() { cout << "No\n"; }

// Const
const int mod = 1000000007;
// 28722900390631
const int inf = 1e18 + 19;
const int MX = 100015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

int n, m, w;
string s[MX];
vi g[MX];
int vis[12][MX];
bool cy;

void dfs(int u, int d)
{
    if (s[u][d] == 'x')
    {
        vis[d][u] = 1;
        return;
    }
    if (vis[d][u] == 2)
    {
        cy = true;
        return;
    }
    if (vis[d][u] == 1)
    {
        return;
    }

    vis[d][u] = 2;

    dfs(u, (d + 1) % w);

    for (auto v : g[u])
    {
        dfs(v, (d + 1) % w);
    }

    vis[d][u] = 1;
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
            int u, v;
            cin >> u >> v;

            g[u].pb(v);
            g[v].pb(u);
        }

        cin >> w;
        ifr(i, 1, n) cin >> s[i];

        ifr(i, 0, w)
        {
            ifr(j, 0, n)
            {
                vis[i][j] = -1;
            }
        }

        cy = false;
        ifr(j, 1, n)
        {
            dfs(j, 0);
            if (cy)
            {
                yes();
                goto done;
            }
        }

        no();

    done:;

        ifr(i, 0, n) g[i].clear();
    }
    return 0;
}
