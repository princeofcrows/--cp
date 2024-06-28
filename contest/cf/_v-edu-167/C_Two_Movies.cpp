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
ll gcd(ll a, ll b) { b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

int a[mx], b[mx];

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n, _a = 0, _b = 0, _c = 0, _d = 0;

        cin >> n;
        fr(i, 0, n) cin >> a[i];
        fr(i, 0, n) cin >> b[i];

        fr(i, 0, n)
        {
            if (a[i] == b[i])
            {
                if (a[i] == 1)
                {
                    _c += a[i];
                }
                else if (a[i] == -1)
                {
                    _d += a[i];
                }
            }
            else
            {
                if (a[i] > b[i])
                {
                    _a += a[i];
                }
                else if (b[i] > a[i])
                {
                    _b += b[i];
                }
            }
        }

        int x = min(_a, _b) + _c;
        int y = max(_a, _b) + _d;

        if (x <= y)
        {
            cout << x << endl;
        }
        else
        {
            x = min(_a, _b);
            y = max(_a, _b);

            while (_c)
            {
                if (x <= y)
                {
                    x++;
                }
                else
                {
                    y++;
                }

                _c--;
            }

            while (_d)
            {
                if (x >= y)
                {
                    x--;
                }
                else
                {
                    y--;
                }

                _d++;
            }

            cout << min(x, y) << endl;
        }
    }
    return 0;
}
