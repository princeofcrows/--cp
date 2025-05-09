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
int ara[MX];
int n, dp[3][31][MX], res;
bool vis[3][31][MX];

int solve(int state, int curMax, int idx)
{
    if (idx > n)
    {
        if (state != 2)
        {
            return -mod;
        }

        return 0;
    }

    if (vis[state][curMax][idx])
    {
        return dp[state][curMax][idx];
    }

    int ret = 0;
    if (state == 0)
    {
        ret = solve(0, 0, idx + 1);
        if (ara[idx] >= 0)
        {
            ret = max(ret, solve(1, ara[idx], idx + 1) + ara[idx]);
            ret = max(ret, solve(2, ara[idx], idx + 1));
        }
    }
    else if (state == 1)
    {
        ret = solve(1, max(curMax, ara[idx]), idx + 1) + ara[idx];
        if (ara[idx] >= curMax)
        {
            ret = max(ret, solve(2, ara[idx], idx + 1));
        }
    }
    else
    {
        if (ara[idx] <= curMax)
        {
            ret = max(ret, solve(2, curMax, idx + 1) + ara[idx]);
        }
    }

    vis[state][curMax][idx] = true;
    return dp[state][curMax][idx] = ret;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    cin >> n;

    ifr(i, 1, n)
    {
        cin >> ara[i];
    }

    mem(vis, false);

    cout << max(solve(0, 0, 1), 0) << endl;

    return 0;
}
