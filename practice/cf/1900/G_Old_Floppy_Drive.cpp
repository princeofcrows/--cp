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
#define mod 1000000007
// 28722900390631
#define inf 1e18 + 19
#define mx 200015
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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

int a[mx], x[mx], _res[mx];

void take_input(int n, int m)
{
    fr(i, 0, n) cin >> a[i];
    fr(i, 0, m) cin >> x[i];
}

vi solve(int n, int m)
{
    int _max = -inf, _sum = 0;

    fr(i, 0, n)
    {
        _sum += a[i];
        _max = max(_max, _sum);
    }

    vi v;
    priority_queue<pii, vpi, greater<pii>> q;
    fr(i, 0, m)
    {
        int _x = x[i];

        if (_sum <= 0 && _max < _x)
        {
            v.pb(-1);
            continue;
        }

        if (_sum <= 0 && _max >= _x)
        {
            q.push({_x, i});
            v.pb(0);
            continue;
        }

        int l = 0, h = mod;

        while (l <= h)
        {
            int mid = (l + h) / 2;
            unsigned long long _sum_rep = mid * _sum + _max;

            if (_sum_rep >= _x)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        q.push({_x - l * _sum, i});
        v.pb(l * n);
    }

    _sum = 0;
    fr(i, 0, n)
    {
        _sum += a[i];
        while (!q.empty())
        {
            auto p = q.top();

            if (p.first > _sum)
            {
                break;
            }

            q.pop();
            v[p.second] += (i);
        }
    }

    return v;
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
        int n, m;
        cin >> n >> m;
        take_input(n, m);
        for (auto u : solve(n, m))
        {
            cout << u << " ";
        }
        cout << "\n";
    }
    return 0;
}
