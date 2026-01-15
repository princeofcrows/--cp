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

int c[4 * MX], dp[MX];

int solve(int i, int n, int w)
{
    if (i > n)
    {
        return c[i] - c[i - w];
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    if (i < w)
    {
        return inf;
    }

    return dp[i] = c[i] - c[i - w] + solve(i + 2 * w, n, w);
};

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n, w;
        cin >> n >> w;
        c[0] = 0;
        dp[0] = -1;

        ifr(i, 1, n)
        {
            cin >> c[i];
            c[i] += c[i - 1];

            dp[i] = -1;
        }

        ifr(i, n + 1, n + 2 * w + 2)
        {
            c[i] = c[i - 1];
        }

        int ans = inf;

        fr(i, 0, w)
        {
            ans = min(ans, solve(i + w, n, w));
            ans = min(ans, solve(i + 2 * w, n, w) + c[i]);

            // cout << i << " " << ans << endl;
        }

        cout << ans << endl;
    }
    return 0;
}
