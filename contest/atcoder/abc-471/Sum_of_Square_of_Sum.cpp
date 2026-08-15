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

int a[MX];

int bm(int _a, int b)
{
    if (b == 0)
        return 1;

    int c = bm(_a, b / 2);
    c = (c * c) % mod;

    if (b % 2)
        c = (c * _a) % mod;

    return c;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n, k;
    cin >> n >> k;
    fr(i, 0, n) cin >> a[i];
    fr(i, 0, n) a[i] %= mod;

    int _n = 1, _r = 1, _nr = 1, _n1 = 1, _nr1 = 1, _r1 = 1;

    ifr(i, 1, n - 1) _n = (_n * i) % mod;
    ifr(i, 1, k - 1) _r = (_r * i) % mod;
    ifr(i, 1, n - k) _nr = (_nr * i) % mod;

    ifr(i, 1, n - 2) _n1 = (_n1 * i) % mod;
    ifr(i, 1, k - 2) _r1 = (_r1 * i) % mod;
    ifr(i, 1, n - k) _nr1 = (_nr1 * i) % mod;

    _r = bm(_r, mod - 2);
    _nr = bm(_nr, mod - 2);
    int co = (_n * _r) % mod;
    co = (co * _nr) % mod;

    _r1 = bm(_r1, mod - 2);
    _nr1 = bm(_nr1, mod - 2);
    int co2 = (_n1 * _r1) % mod;
    co2 = (co2 * _nr1) % mod;
    if (k < 2)
        co2 = 0;

    int ans = 0;

    fr(i, 0, n) ans = (ans + (((a[i] * a[i]) % mod) * co) % mod) % mod;

    int tot = 0;
    fr(i, 0, n) tot = (tot + a[i]) % mod;

    int ans2 = 0;
    fr(i, 0, n)
    {
        tot = (-a[i] + tot + mod) % mod;
        int ab = (a[i] * tot) % mod;
        // ab = (ab * co) % mod;
        ab = (ab * co2) % mod;

        ans2 = (ans2 + 2 * ab) % mod;
    }

    cout << (ans + ans2) % mod << endl;
    return 0;
}
