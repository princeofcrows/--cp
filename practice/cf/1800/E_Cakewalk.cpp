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

int dp[6][6];
int h, w;
string str[7];
vpi v;

int solve(int i, int j)
{
    if (i >= h || i < 0 || j >= w || j < 0)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int co = (int)(str[i][j] == '*');
    int x = h, y = w, d = abs(i - x) + abs(j - y);

    for (auto p : v)
    {
        if (p.fi >= i && p.se >= j)
        {
            if (p.fi != i || p.se != j)
            {
                int dt = abs(i - p.fi) + abs(j - p.se);
                if (dt < d)
                {
                    d = dt;
                    x = p.fi;
                    y = p.se;
                }
            }
        }
    }
    int ret = solve(x, y) + co;
    return dp[i][j] = ret;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;
    cin >> h >> w;

    fr(i, 0, h)
    {
        cin >> str[i];
    }
    mem(dp, -1);
    fr(i, 0, h)
    {
        fr(j, 0, w)
        {
            if (str[i][j] == '*')
            {
                v.pb({i, j});
            }
        }
    }

    cout << solve(0, 0);
    return 0;
}
