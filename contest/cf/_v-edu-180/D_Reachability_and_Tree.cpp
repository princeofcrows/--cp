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

int in[MX], _ml, l[MX];
vi g[MX];

void init(int n)
{
    fr(i, 0, n + 1)
    {
        in[i] = 0;
        g[i].clear();
    }
}

void print_dfs(int u, int p, int is_out)
{
    if (p == -1)
    {
        assert(g[u].size() == 2);
        int frst = g[u][0];
        int scnd = g[u][1];

        cout << frst << " " << u << endl;
        cout << u << " " << scnd << endl;

        print_dfs(frst, u, true);
        print_dfs(scnd, u, false);

        return;
    }

    for (auto v : g[u])
    {
        if (v == p)
        {
            continue;
        }

        if (is_out)
        {
            cout << u << " " << v << endl;
            print_dfs(v, u, 0);
        }
        else
        {
            cout << v << " " << u << endl;
            print_dfs(v, u, 1);
        }
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
        int n;
        cin >> n;
        init(n);

        fr(i, 0, n - 1)
        {
            int u, v;
            cin >> u >> v;

            g[u].pb(v);
            g[v].pb(u);

            in[v]++;
            in[u]++;
        }

        if (n == 2)
        {
            no();
            continue;
        }

        int root = -1;
        ifr(i, 1, n)
        {
            if (in[i] == 2)
            {
                root = i;
            }
        }

        if (root == -1)
        {
            no();
            continue;
        }

        yes();
        print_dfs(root, -1, false);
    }
    return 0;
}