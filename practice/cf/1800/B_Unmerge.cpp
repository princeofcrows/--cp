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
ll gcd(ll a, ll b) { return b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

// random
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

int ara[4002], nxt[4002];
bool dp[4002][8002], vis[4002][8002];
int n;

void init()
{
    ifr(i, 0, 2 * n) ifr(j, 0, 4 * n) vis[i][j] = false;

    fr(i, 0, 2 * n)
    {
        nxt[i] = 2 * n;
        fr(j, i + 1, 2 * n)
        {
            if (ara[j] > ara[i])
            {
                nxt[i] = j;
                i = j - 1;
                break;
            }
        }
    }
}

bool solve(int last, int value)
{
    // cout << last << "  " << value << endl;
    if (last >= 2 * n)
    {
        if (value == 2 * n)
        {
            return true;
        }

        return false;
    }

    if (vis[last][value])
    {
        return dp[last][value];
    }

    bool ret = false;

    int inc = nxt[last] - last;
    ret = ret || solve(nxt[last], value + inc);
    ret = ret || solve(nxt[last], value - inc);

    vis[last][value] = true;
    return dp[last][value] = ret;
}

int32_t main()
{
    // rin();
    //  wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        fr(i, 0, 2 * n) cin >> ara[i];

        init();

        solve(0, 2 * n) ? yes() : no();
    }
    return 0;
}
