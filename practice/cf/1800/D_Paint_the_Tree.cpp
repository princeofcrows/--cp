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

// Const
#define mod 1000000007
// 28722900390631
#define inf 1e18 + 19
#define mx 200015
#define pi acos(-1.0)
#define seed 997
// 769 919 647 839

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
ll gcd(ll a, ll b) { b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

int c[4][mx];
vi g[mx];
int dp[mx][4][4], sNode, path[mx];

int solve(int i, int p, int l, int lil)
{
    if (dp[i][l][lil] != -1)
    {
        return dp[i][l][lil];
    }

    int ret = 0;
    int co = (l ^ lil);

    for (auto u : g[i])
    {
        if (u != p)
        {
            ret = solve(u, i, co, l);
        }
    }

    return dp[i][l][lil] = ret + c[co][i];
}

void prPath(int i, int p, int l, int lil)
{
    int co = (l ^ lil);
    path[i] = co;

    // cout << path[i] << " " << i << " " << sNode << endl;

    for (auto u : g[i])
    {
        if (u != p)
        {
            prPath(u, i, co, l);
        }
    }
}

bool isLine(int n)
{
    ifr(i, 1, n)
    {
        if (g[i].size() > 2)
        {
            return false;
        }

        if (g[i].size() == 1)
        {
            sNode = i;
        }
    }

    return true;
}

void print(int res)
{
    ifr(i, 1, 3)
    {
        ifr(j, 1, 3)
        {
            if (i != j)
            {
                int x = solve(sNode, -1, i, j);
                if (x == res)
                {
                    prPath(sNode, -1, i, j);
                    return;
                }
            }
        }
    }
}

int32_t main()
{
    // rin();
    // wrout();
    fst;
    mem(dp, -1);
    int n;
    cin >> n;

    ifr(i, 1, 3)
    {
        ifr(j, 1, n)
        {
            cin >> c[i][j];
        }
    }
    fr(i, 1, n)
    {
        int a, b;
        cin >> a >> b;

        g[a].pb(b);
        g[b].pb(a);
    }

    if (!isLine(n))
    {
        cout << -1 << endl;
    }
    else
    {

        int ans = inf;
        ifr(i, 1, 3)
        {
            ifr(j, 1, 3)
            {
                if (i != j)
                {
                    ans = min(ans, solve(sNode, -1, i, j));
                }
            }
        }

        cout << ans << endl;
        print(ans);

        ifr(i, 1, n) cout << path[i] << " ";
        cout << endl;
    }
    return 0;
}
