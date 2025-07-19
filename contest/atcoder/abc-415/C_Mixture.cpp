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
void yes() { cout << "Yes\n"; }
void no() { cout << "No\n"; }

// Const
const int mod = 1000000007;
// 28722900390631
const int inf = 1e18 + 19;
const int MX = 200015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

vi g[22];
bool dp[(1 << 20)][20], vis[(1 << 20)][20];
int lim;

bool dfs(int musk, int idx, int n)
{
    // cout << musk << " " << idx << endl;
    if (idx > n)
    {
        if (musk == lim)
        {
            return true;
        }

        return false;
    }
    if (vis[musk][idx])
    {
        return dp[musk][idx];
    }

    bool ret = false;
    for (auto u : g[idx])
    {
        int x = (musk | u);
        if (x == u)
        {
            ret |= dfs(u, idx + 1, n);
            if (ret)
            {
                break;
            }
        }
    }

    vis[musk][idx] = true;
    return dp[musk][idx] = ret;
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
        string s;
        cin >> n >> s;
        lim = ((1 << n) - 1);

        int ans = 0;
        fr(i, 0, lim)
        {
            if (s[i] == '0')
            {
                g[__builtin_popcount(i + 1)].pb(i + 1);
                // cout << i + 1 << " " << __builtin_popcount(i + 1) << endl;
            }
        }

        fr(i, 0, (1 << n))
        {
            ifr(j, 0, n)
            {
                dp[i][j] = false;
                vis[i][j] = false;
            }
        }

        if (dfs(0, 1, n))
        {
            yes();
        }
        else
        {
            no();
        }

        ifr(i, 0, n) g[i].clear();
    }
    return 0;
}
