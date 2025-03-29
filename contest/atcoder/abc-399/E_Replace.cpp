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

int g[27];
int vis[27], cnt;

bool dfs(int u)
{
    if (g[u] == -1)
    {
        cnt = 1;
        return true;
    }

    if (g[u] == u)
    {
        return true;
    }

    if (vis[u] == 1)
    {
        return false;
    }

    vis[u] = 1;

    bool f = dfs(g[u]);
    vis[u] = 2;

    return f;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n, ans = 0, con = 0;
    string s, t;
    cin >> n >> s >> t;
    si xx;

    mem(g, -1);
    fr(i, 0, n)
    {
        int x = s[i] - 'a';
        int y = t[i] - 'a';
        xx.insert(y);

        if (g[x] == -1)
        {
            g[x] = y;
            if (x != y)
            {
                ans++;
            }
        }
        else
        {
            if (g[x] != y)
            {
                ans = -1;
                break;
            }
        }
    }
    if (ans == 1)
    {
        cout << ans << endl;
        return 0;
    }

    mem(vis, 0);
    cnt = 0;
    ifr(i, 0, 26)
    {
        if (!vis[i])
        {
            if (!dfs(i))
            {
                con += 1;
            }
        }
    }

    if (con && xx.size() == 26)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << ans + con << endl;
    return 0;
}
