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
const int mod = 998244353;
// 28722900390631
const int inf = 1e18 + 19;
const int MX = 200015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

int a[MX], dp[MX];
mii mp;

bool isAllOk(int n)
{
    return a[n - 1] - a[n - 2] < 2;
}

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = (n * fact(n - 1)) % mod;
}

long long binPowRec(long long a, long long b)
{
    if (b == 0)
        return 1;

    long long res = binPowRec(a, b / 2);
    long long c = (res * res) % mod;

    if (b % 2)
    {
        c = (c * a) % mod;
    }
    return c;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;
    mem(dp, -1);

    while (t--)
    {
        mp.clear();

        int n;
        cin >> n;

        fr(i, 0, n) cin >> a[i];
        fr(i, 0, n) mp[a[i]]++;

        sort(a, a + n);

        if (!isAllOk(n))
        {
            cout << 0 << endl;
            continue;
        }

        if (mp[a[n - 1]] > 1)
        {
            cout << fact(n) << endl;
            continue;
        }

        int ans = fact(n), lastCnt = mp[a[n - 2]];
        fr(i, lastCnt, n)
        {
            int m = i;
            int right = fact(m);
            int x = fact(m - lastCnt);
            right = (right * binPowRec(x, mod - 2)) % mod;

            int rest = fact(n - 1 - lastCnt);

            //cout << i << " " << right << " " << rest << endl;

            int now = (right * rest) % mod;
            ans = (ans - now + mod) % mod;
        }

        cout << ans << endl;
    }
    return 0;
}
