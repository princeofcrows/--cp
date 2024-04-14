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
#define mod 998244353
// 28722900390631
#define inf 1e18 + 19
#define mx 500015
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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

int a[mx], dp[2][mx], n;
vi v[mx];

int solve(int i, int t)
{
    if (i >= n)
    {
        return 0;
    }

    if (dp[t][i] != -1)
    {
        return dp[t][i];
    }

    int ret = 1;
    int id1 = upper_bound(v[a[i]].begin(), v[a[i]].end(), i) - v[a[i]].begin();

    if (id1 < v[a[i]].size())
    {
        ret = (ret + solve(v[a[i]][id1], t)) % mod;
    }

    if (t == 0)
    {
        int id2 = upper_bound(v[a[i] + 1].begin(), v[a[i] + 1].end(), i) - v[a[i] + 1].begin();

        if (id2 < v[a[i] + 1].size())
        {
            ret = (ret + solve(v[a[i] + 1][id2], 0)) % mod;
        }

        int id3 = upper_bound(v[a[i] + 2].begin(), v[a[i] + 2].end(), i) - v[a[i] + 2].begin();

        if (id3 < v[a[i] + 2].size())
        {
            ret = (ret + solve(v[a[i] + 2][id3], 1)) % mod;
        }
    }

    return dp[t][i] = ret;
}

void init(int n)
{
    fr(i, 0, n + 1)
    {
        fr(j, 0, 2)
        {
            dp[j][i] = -1;
        }
        v[i].clear();
    }
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    sid(t);

    while (t--)
    {
        sid(n);

        init(n);
        fr(i, 0, n)
        {
            sid(a[i]);
            v[a[i]].pb(i);
        }

        int ans = 0;
        fr(i, 0, n)
        {
            if (a[i] == 0)
            {
                ans = (ans + solve(i, 0)) % mod;
                // break;
            }
        }

        fr(i, 0, n)
        {
            if (a[i] == 1)
            {
                ans = (ans + solve(i, 1)) % mod;
                // break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
