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

int a[mx], dp[2][mx];

void init(int n)
{
    fr(i, 0, n + 10)
    {
        fr(j, 0, 2)
        {
            dp[j][i] = 0;
        }
    }
}

int sumMod(int x, int y)
{
    return ((x + y) % mod + mod) % mod;
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
        int n;
        sid(n);
        init(n);

        int ans = 0;
        fr(i, 0, n)
        {
            sid(a[i]);

            int l = 0, h = 0;

            l = sumMod(l, dp[0][a[i]]) + (a[i] == 0 ? 1 : 0);
            h = sumMod(h, dp[1][a[i]]) + (a[i] == 1 ? 1 : 0);

            int x = a[i] - 1;

            if (x >= 0)
            {
                l = sumMod(l, dp[0][x]);
            }

            x = a[i] + 2;

            // if (x <= n)
            // {
            //     l = sumMod(l, dp[1][x]);
            // }

            x = a[i] - 2;

            if (x >= 0)
            {
                h = sumMod(h, dp[0][x]);
            }

            dp[0][a[i]] = sumMod(dp[0][a[i]], l);
            dp[1][a[i]] = sumMod(dp[1][a[i]], h);

            cout << a[i] << "-->>" << l << "-->" << dp[0][a[i]] << "-------"
                 << h << "-->" << dp[1][a[i]] << endl;
        }

        ifr(i, 0, n + 1)
        {
            ans = (ans + dp[0][i] + dp[1][i]) % mod;
        }

        cout << ans << endl;
    }
    return 0;
}