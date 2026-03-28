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
const int MX = 300015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

int a[MX], ans[2][MX];

void solve(int n, int idx)
{
    vi v, sz(n + 1);

    fr(i, 0, n)
    {
        if (!v.empty())
        {
            v.push_back(v.back() + a[i]);
        }
        else
        {
            v.push_back(a[i]);
        }
        // cout << v.back() << " ";
    }

    v.pb(inf);
    a[n] = inf;

    fr(i, 0, n)
    {
        if (!i)
        {
            sz[i] = -1;
        }
        else
        {
            sz[i] = (a[i] == a[i - 1] ? sz[i - 1] : i - 1);
        }
    }

    sz[n] = sz[n - 1] + 1;

    fr(i, 0, n)
    {
        int l = i + 1, h = n;

        while (l <= h)
        {
            int m = (l + h) / 2;

            if (sz[m] < i)
            {
                l = m + 1;
            }
            else if (sz[m] == i && a[m] <= a[i])
            {
                l = m + 1;
            }
            else if (v[m] <= v[i] + a[i])
            {
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }

        // cout << idx << " " << i << " " << l << endl;
        ans[idx][i] = l >= n ? inf : l - i;
    }
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
        int n;
        cin >> n;
        fr(i, 0, n)
        {
            cin >> a[i];
        }

        solve(n, 0);

        reverse(a, a + n);
        solve(n, 1);

        fr(i, 0, n)
        {
            int _ans = min(ans[0][i], ans[1][n - i - 1]);

            cout << (_ans > n ? -1 : _ans) << " ";
        }
        cout << endl;
    }
    return 0;
}
