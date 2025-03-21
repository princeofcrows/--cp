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

int n;
int a[MX], in[MX], out[MX], root_tot, csum[MX], tot_a;
vi order, g[MX];

void construct_dfs(int u, int p, int l)
{
    order.pb(u);
    in[u] = order.size() - 1;

    csum[order.size()] = a[u];
    csum[order.size()] += csum[order.size() - 1];

    root_tot += (l * a[u]);

    for (auto v : g[u])
    {
        if (v != p)
        {
            construct_dfs(v, u, l + 1);
        }
    }

    out[u] = order.size() - 1;
}

int solve_dfs(int u, int p, int pv)
{
    int res = pv + tot_a - 2 * (csum[out[u] + 1] - csum[in[u]]);
    int ans = res;

    for (auto v : g[u])
    {
        if (v != p)
        {
            ans = max(ans, solve_dfs(v, u, res));
        }
    }

    return ans;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;
    cin >> n;
    tot_a = 0;
    ifr(i, 1, n)
    {
        cin >> a[i];
        tot_a += a[i];
    }

    fr(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    root_tot = 0;
    construct_dfs(1, -1, 0);
    // cout << root_tot << endl;

    cout << solve_dfs(1, -1, root_tot + tot_a);
    return 0;
}
