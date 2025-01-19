#include <bits/stdc++.h>

using namespace std;

// Data type
// #define int long long
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

int n, m1, m2;
vi f[MX], g[MX], x[MX];
bool vis[MX], vis_x[MX];
set<int> curr;

void inpt() {
    cin >> n >> m1 >> m2;

    fr(i, 0, m1) {
        int a, b;
        cin >> a >> b;
        f[a].pb(b);
        f[b].pb(a);
    }

    fr(i, 0, m2) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    ifr(i, 0, n) {
        vis[i] = false;
        vis_x[i] = false;
    }
}

void dfs(int u) {
    vis[u] = true;
    curr.insert(u);

    for (auto v : g[u]) {
        if (vis[v]) {
            continue;
        }

        dfs(v);
    }
}

void dfs2(int u) {
    vis_x[u] = true;

    for (auto v : x[u]) {
        if (vis_x[v]) {
            continue;
        }

        dfs2(v);
    }
}

int solve() {
    int ans = 0, del = 0, ins = 0;
    ifr(i, 1, n) {
        if (vis[i]) {
            continue;
        }

        dfs(i);

        for (auto u : curr) {
            for (auto v : f[u]) {
                if (!curr.count(v)) {
                    del++;
                }
                else {
                    x[u].pb(v);
                }
            }
        }

        int isl = 0;
        for (auto u : curr) {
            if (vis_x[u]) {
                continue;
            }

            dfs2(u);
            isl++;
        }

        curr.clear();
        ans += (isl - 1);
    }

    return ans + (del / 2);
}

void clear() {
    ifr(i, 0, n) {
        f[i].clear();
        g[i].clear();
        x[i].clear();
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
        inpt();
        cout << solve() << endl;
        clear();
    }
    return 0;
}
