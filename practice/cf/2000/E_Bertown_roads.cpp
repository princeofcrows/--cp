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
const int MX = 100015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

vector<pair<int, int>> br, res;
int Time;
int low[MX], disc[MX], vis[3 * MX];
vpi adj[MX];

void dfsBR(int u, int p)
{

    low[u] = disc[u] = ++Time;
    for (auto v : adj[u])
    {
        if (v.fi == p)
        {
            continue;
        }

        if (!disc[v.fi])
        {
            dfsBR(v.fi, u);
            if (disc[u] < low[v.fi])
            {
                br.push_back({u, v.fi});
            }
            low[u] = min(low[u], low[v.fi]);
        }
        else
        {
            low[u] = min(low[u], disc[v.fi]);
        }

        if (!vis[v.se])
        {
            vis[v.se] = 1;
            res.pb({u, v.fi});
        }
    }
}

void BR(int n)
{
    mem(disc, 0);
    mem(low, 0);
    Time = 0;
    for (int u = 1; u <= n; u++)
        if (!disc[u])
        {
            dfsBR(u, u);
        }
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n, m;
    cin >> n >> m;

    fr(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb({b, i});
        adj[b].pb({a, i});
    }

    BR(n);

    if (br.size() > 0)
    {
        cout << 0;
    }
    else
    {
        for (auto u : res)
        {
            cout << u.fi << " " << u.se << endl;
        }
    }
    return 0;
}
