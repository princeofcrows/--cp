#include <bits/stdc++.h>

using namespace std;

// Data type
#define int short int
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

int dp[201][201][201];

int solve(int one, int two, int three)
{
    if (one == 0 && two == 0 && three == 0)
    {
        return 0;
    }

    if (dp[one][two][three] != -1)
    {
        return dp[one][two][three];
    }

    int xr = 0;
    if (one % 2)
    {
        xr ^= 1;
    }

    if (two % 2)
    {
        xr ^= 2;
    }

    if (three % 2)
    {
        xr ^= 3;
    }

    int _one = one ? solve(one - 1, two, three) : 0;
    int _two = two ? solve(one, two - 1, three) : 0;
    int _three = three ? solve(one, two, three - 1) : 0;

    int ret = max(_one, _two);
    ret = max(ret, _three);

    if (xr == 0)
    {
        return dp[one][two][three] = ret + 1;
    }

    return dp[one][two][three] = ret;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    mem(dp, -1);

    int t;
    cin >> t;

    while (t--)
    {
        int o, tw, th, f;
        cin >> o >> tw >> th >> f;
        cout << solve(o, tw, th) + f / 2 << endl;
    }
    return 0;
}