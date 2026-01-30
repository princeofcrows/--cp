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

int c[MX], id[MX], res[MX], cnt[MX], ans[MX];

mii s[MX];
vi g[MX];

void merge(int a, int b)
{

    if (s[id[a]].size() < s[id[b]].size())
    {
        swap(id[a], id[b]);
    }

    int big = id[a];
    int small = id[b];

    for (auto u : s[small])
    {
        s[big][u.fi] += u.se;
        auto tot = s[big][u.fi];

        if (tot > cnt[big])
        {
            cnt[big] = tot;
            res[big] = u.fi;
        }
        else if (tot == cnt[big])
        {
            // cout << big << " " << u.fi << endl;
            res[big] += u.fi;
        }
    }
}

void dfs(int u, int p)
{
    id[u] = u;
    s[u][c[u]] = 1;
    res[u] = c[u];
    cnt[u] = 1;

    for (auto v : g[u])
    {
        if (v != p)
        {
            dfs(v, u);
            merge(u, v);
        }
    }

    ans[u] = res[id[u]];
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n;
    cin >> n;

    ifr(i, 1, n) cin >> c[i];

    fr(i, 1, n)
    {
        int x, y;
        cin >> x >> y;

        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1, 0);

    ifr(i, 1, n) cout << ans[i] << " ";
    return 0;
}
