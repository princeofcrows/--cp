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

double f(int tot, int h, int c, int t)
{
    int _h = (tot + 1) / 2LL;
    int _c = tot / 2LL;
    return llabs(h * _h + c * _c - t * tot) * 1.0 / (tot * 1.0);
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int T;
    cin >> T;

    while (T--)
    {
        int c, h, t;
        cin >> h >> c >> t;

        int low = 1, high = mod, even, odd;
        while (low <= high)
        {

            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;

            double d1 = f(mid1 * 2, h, c, t);
            double d2 = f(mid2 * 2, h, c, t);

            if (d1 <= d2)
            {
                high = mid2 - 1;
                even = mid1;
            }
            else
            {
                low = mid1 + 1;
                even = mid2;
            }
        }

        low = 1, high = mod;
        while (low <= high)
        {

            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;

            double d1 = f(mid1 * 2 - 1, h, c, t);
            double d2 = f(mid2 * 2 - 1, h, c, t);

            if (d1 <= d2)
            {
                high = mid2 - 1;
                odd = mid1;
            }
            else
            {
                low = mid1 + 1;
                odd = mid2;
            }
        }

        if (f(odd * 2 - 1, h, c, t) < f(even * 2, h, c, t))
        {
            cout << odd * 2 - 1 << endl;
        }
        else
        {
            cout << even * 2 << endl;
        }

        // fr(i, 1, 10)
        // {
        //     cout << fixed;
        //     cout << setprecision(5) << f(i, h, c, t) << endl;
        // }
    }
    return 0;
}
