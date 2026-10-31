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

vi r, c;

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int h, w, n, q;
    cin >> h >> w >> n >> q;

    fr(i, 0, n)
    {
        int x, y;
        cin >> x >> y;

        r.pb(x);
        c.pb(y);
    }

    sort_all(r);
    sort_all(c);

    while (q--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int u, d;
            cin >> u >> d;

            int s = lower_bound(r.begin(), r.end(), u) - r.begin();
            int e = upper_bound(r.begin(), r.end(), d) - r.begin();

            cout << e - s << endl;
        }
        else
        {
            int l, _r;
            cin >> l >> _r;

            int s = lower_bound(c.begin(), c.end(), l) - c.begin();
            int e = upper_bound(c.begin(), c.end(), _r) - c.begin();

            cout << e - s << endl;
        }
    }

    return 0;
}
