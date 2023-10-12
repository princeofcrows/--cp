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
#define mod 998244353
// 28722900390631
#define inf 1e18 + 19
#define mx 300015
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

int f[mx];
void gen(int n)
{
    f[0] = 1;
    ifr(i, 1, n) f[i] = (f[i - 1] * i) % mod;
}

int bigMod(int a, int b)
{
    if (b <= 0)
        return 1 % mod;

    int c = bigMod(a, b / 2);
    c = (c * c) % mod;

    if (b % 2)
        c = (c * a) % mod;

    return c;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n, k;
    cin >> n >> k;

    vpi v(n);

    fr(i, 0, n)
    {
        cin >> v[i].fi >> v[i].se;
    }

    sort(v.begin(), v.end());

    int ans = 0;
    gen(n);
    int revK = bigMod(f[k - 1], mod - 2);

    priority_queue<int, vi, greater<int>> q;
    fr(i, 0, n)
    {
        while (!q.empty() && q.top() < v[i].fi)
        {
            q.pop();
        }

        int pick = q.size();
        // cout << v[i].fi << " " << v[i].se << " " << pick << " " << k - 1 << endl;

        if (pick >= k - 1)
        {
            int nr = bigMod(f[pick - k + 1], mod - 2);
            int rn = (f[pick] * revK) % mod;
            int ncr = (rn * nr) % mod;

            ans = (ans + ncr) % mod;
        }

        q.push(v[i].se);
    }

    cout << ans << endl;
    return 0;
}
