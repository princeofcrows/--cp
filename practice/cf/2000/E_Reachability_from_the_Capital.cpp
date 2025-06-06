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

stack<int> stk;
int vis[5005], cy, containsS;
vector<int> g[5005], order;
map<pii, int> mp;

void toposort(int u)
{
    if (vis[u])
    {
        if (vis[u] == 1)
            cy = true;
        return;
    }
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++)
    {
        toposort(g[u][i]);
    }
    stk.push(u);
    vis[u] = 2;
}

void inittoposort(int n)
{
    cy = false;
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            toposort(i);
        }
    }
    while (!stk.empty())
    {
        order.push_back(stk.top());
        // cout << stk.top() << " ";
        stk.pop();
    }
}

void dfs(int u, int s)
{
    if (vis[u])
    {
        if (vis[u] == 1)
            cy = true;
        return;
    }

    if (u == s)
    {
        containsS = 1;
    }
    vis[u] = 1;

    for (auto v : g[u])
    {
        dfs(v, s);
    }

    vis[u] = 2;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n, m, s;
    cin >> n >> m >> s;

    fr(i, 0, m)
    {
        int a, b;
        cin >> a >> b;

        if (a == s)
            a = 1;
        else if (a == 1)
            a = s;

        if (b == s)
            b = 1;
        else if (b == 1)
            b = s;

        g[a].pb(b);
    }

    ifr(i, 1, n) sort_all(g[i]);
    s = 1;

    inittoposort(n);

    mem(vis, 0);
    int ans = 0;
    for (auto u : order)
    {
        if (!vis[u])
        {
            cy = 0;
            containsS = 0;
            dfs(u, s);
            if (u == s)
            {
                continue;
            }

            // cout << u << endl;
            ans++;
        }
    }

    cout << ans;
    return 0;
}
