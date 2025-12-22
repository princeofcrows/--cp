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

int a[5000], b[5000];
vi dp[5000];

int calc(int i, int j)
{
    if (i == j)
    {
        return a[i] * b[j];
    }
    if (i > j)
    {
        return 0;
    }

    if (dp[j][i] != -1)
    {
        return dp[j][i];
    }

    return dp[j][i] = a[j] * b[i] + a[i] * b[j] + calc(i + 1, j - 1);
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n;
    cin >> n;

    fr(i, 0, n) cin >> a[i];
    fr(i, 0, n) cin >> b[i];

    fr(j, 0, n) fr(i, 0, j) dp[j].pb(-1);

    int frd = 0, ans = 0;
    fr(i, 0, n)
    {
        int bck = 0;
        rfr(j, n, i)
        {
            int rev = calc(i, j);
            int _ans = frd + bck + rev;
            ans = max(_ans, ans);

            // cout << frd << " " << rev << " " << bck << endl;
            bck += a[j] * b[j];
        }

        frd += a[i] * b[i];
    }

    cout << ans << endl;
    return 0;
}
