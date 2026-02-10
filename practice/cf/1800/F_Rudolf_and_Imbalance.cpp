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

int n, m, k;
int a[MX], d[MX], f[MX];

bool can(int r)
{
    vpi dif;

    fr(i, 0, n - 1)
    {
        if (a[i + 1] - a[i] > r)
        {
            int _max = a[i] + r;
            int _min = a[i + 1] - r;

            if (_max < _min)
            {
                return false;
            }

            dif.pb({_min, _max});
        }
    }

    if (dif.empty())
    {
        return true;
    }

    if (dif.size() > 1)
    {
        return false;
    }

    fr(i, 0, m)
    {
        int need = dif[0].fi - d[i];
        int idx = lower_bound(f, f + k, need) - f;

        if (idx < k)
        {
            int x = d[i] + f[idx];

            if (x >= dif[0].fi && x <= dif[0].se)
            {
                return true;
            }
        }
    }

    return false;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m >> k;

        fr(i, 0, n) cin >> a[i];
        fr(i, 0, m) cin >> d[i];
        fr(i, 0, k) cin >> f[i];

        sort(d, d + m);
        sort(f, f + k);

        int l = 0, h = 2 * mod;

        while (l <= h)
        {
            int mid = (l + h) / 2;

            if (!can(mid))
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        cout << l << endl;
    }

    return 0;
}
