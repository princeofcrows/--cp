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

int a[55];
int f[56], ncr[55][55];

int fact(int i) {
    if (i == 0) return 1;
    if (f[i] != -1) return f[i];

    return f[i] = (i * fact(i - 1)) % mod;
}

int nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (ncr[n][r] != -1) return ncr[n][r];

    return ncr[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % mod;
}


int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    mem(ncr, -1); mem(f, -1);

    while (t--)
    {
        int n; cin >> n;

        ifr(i, 0, n) cin >> a[i];

        int sum = 0;
        ifr(i, 0, n) sum += a[i];

        int each = sum / n;
        int rem = sum % n;

        bool cant = false;
        int zeros = 0, ones = 0;

        ifr(i, 1, n) {
            a[i] -= each;
            if (a[i] < 0) {
                a[0] += a[i];
                a[i] = 0;
            }
            if (a[i] > 1) cant = true;

            zeros += (a[i] == 0);
            // rem -= (a[i] == 1);
            ones += (a[i] == 1);
        }

        if (cant || a[0] > zeros || a[0] < 0) {
            cout << 0 << endl;
            continue;
        }

        // assert(rem == a[0]);
        int ans = (fact(ones + a[0]) * fact(n - ones - a[0])) % mod;
        ans = (ans * nCr(zeros, a[0])) % mod;

        cout << ans << endl;
    }
    return 0;
}
