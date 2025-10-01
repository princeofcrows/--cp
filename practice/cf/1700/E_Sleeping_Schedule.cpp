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
int n, h, l, r, a[2005];
int dp[2002][2002];

int solve(int i, int s)
{
    if (i >= n)
    {
        return 0;
    }

    if (dp[i][s] != -1)
    {
        return dp[i][s];
    }

    int ret = 0;
    int _s1 = (s + a[i]) % h;
    int _co1 = (_s1 >= l && _s1 <= r);
    int ret1 = solve(i + 1, _s1) + _co1;

    int _s2 = (s + a[i] - 1 + h) % h;
    int _co2 = (_s2 >= l && _s2 <= r);
    int ret2 = solve(i + 1, _s2) + _co2;

    ret = max(ret1, ret2);

    return dp[i][s] = ret;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    cin >> n >> h >> l >> r;

    fr(i, 0, n) cin >> a[i];
    mem(dp, -1);

    cout << solve(0, 0);
    return 0;
}
