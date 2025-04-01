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

int a[MX], ara[MX];

vpi pos(int n)
{
    int idx_max = -1, _max = -223, idx_min = -1, _min = 223;
    vpi res;

    fr(i, 0, n)
    {
        if (a[i] < _min)
        {
            _min = a[i];
            idx_min = i;
        }

        if (a[i] > _max)
        {
            _max = a[i];
            idx_max = i;
        }
    }

    if (_min < 0 && _max > 0 && _max < abs(_min))
    {
        while (a[idx_max] < abs(_min))
        {
            a[idx_max] += a[idx_max];
            res.pb({idx_max, idx_max});
        }
    }

    fr(i, 0, n)
    {
        if (a[i] < 0)
        {
            a[i] += a[idx_max];
            res.pb({i, idx_max});
        }
    }

    fr(i, 1, n)
    {
        if (a[i] < a[i - 1])
        {
            a[i] += a[i - 1];
            res.pb({i, i - 1});
        }
    }

    return res;
}

vpi neg(int n)
{
    int idx_max = -1, _max = -223, idx_min = -1, _min = 223;
    vpi res;

    fr(i, 0, n)
    {
        if (a[i] < _min)
        {
            _min = a[i];
            idx_min = i;
        }

        if (a[i] > _max)
        {
            _max = a[i];
            idx_max = i;
        }
    }

    if (_max > 0 && _min < 0 && abs(_min) < _max)
    {
        while (abs(a[idx_min]) < _max)
        {
            a[idx_min] += a[idx_min];
            res.pb({idx_min, idx_min});
        }
    }

    fr(i, 0, n)
    {
        if (a[i] > 0)
        {
            a[i] += a[idx_min];
            res.pb({i, idx_min});
        }
    }

    rfr(i, n - 1, 0)
    {
        if (a[i] > a[i + 1])
        {
            a[i] += a[i + 1];
            res.pb({i, i + 1});
        }
    }

    return res;
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

        bool isPos = false, isNeg = false;
        fr(i, 0, n)
        {
            cin >> ara[i];

            if (ara[i] > 0)
            {
                isPos = true;
            }
            else if (ara[i] < 0)
            {
                isNeg = true;
            }
        }

        if (isPos)
        {
            fr(i, 0, n) a[i] = ara[i];
            auto r1 = pos(n);

            if (r1.size() < 32)
            {
                cout << r1.size() << "\n";
                for (auto u : r1)
                {
                    cout << u.fi + 1 << " " << u.se + 1 << "\n";
                }
                continue;
            }
        }

        if (isNeg)
        {
            fr(i, 0, n) a[i] = ara[i];
            auto r2 = neg(n);

            if (r2.size() < 32)
            {
                cout << r2.size() << "\n";
                for (auto u : r2)
                {
                    cout << u.fi + 1 << " " << u.se + 1 << "\n";
                }
                continue;
            }
        }

        if (!isPos && !isNeg)
        {
            cout << 0 << "\n";
            continue;
        }

        assert(true == false);
    }
    return 0;
}
