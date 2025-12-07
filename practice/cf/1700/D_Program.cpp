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

string str;
int cu[2][MX];
int _max[2][MX], _min[2][MX];

int32_t
main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m >> str;

        _min[0][0] = _min[1][n + 1] = _max[0][0] = _max[1][n + 1] = cu[0][0] = 0;

        fr(i, 0, n)
        {
            cu[0][i + 1] = cu[0][i] + (str[i] == '-' ? -1 : 1);
            _max[0][i + 1] = max(cu[0][i + 1], _max[0][i]);
            _min[0][i + 1] = min(cu[0][i + 1], _min[0][i]);
            // cout << cu[0][i + 1] << " " << _max[0][i + 1] << " " << _min[0][i + 1] << endl;
        }

        rfr(i, n, 0)
        {
            cu[1][i + 1] = (str[i] == '-' ? -1 : 1);
            _max[1][i + 1] = max(cu[1][i + 1] + _max[1][i + 2], 0);
            _min[1][i + 1] = min(cu[1][i + 1] + _min[1][i + 2], 0);
        }

        while (m--)
        {
            int l, r;
            cin >> l >> r;

            int r_max = max(0, _max[1][r + 1] + cu[0][l - 1]);
            int r_min = min(0, _min[1][r + 1] + cu[0][l - 1]);

            // cout << r_max << " " << r_min << endl;
            // cout << _max[0][l - 1] << " " << _min[0][l - 1] << endl;

            cout << max(_max[0][l - 1], r_max) - min(_min[0][l - 1], r_min) + 1 << endl;
        }
    }
    return 0;
}
