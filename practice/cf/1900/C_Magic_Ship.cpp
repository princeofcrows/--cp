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

int _dx[MX], _dy[MX];

bool solve(int dys, int _x, int _y, int n)
{
    if (dys <= n)
    {
        int dx = _dx[dys];
        int dy = _dy[dys];

        int dif_x = (llabs(_x - dx));
        int dif_y = (llabs(_y - dy));

        // cout << dys << " " << dif_x << " " << dif_y << " " << dx << " " << dy << endl;

        if (dif_x + dif_y <= dys)
        {
            return true;
        }

        return false;
    }

    int rem = dys % n;
    int rept = (dys / n);
    int dx = _dx[rem] + _dx[n] * rept;
    int dy = _dy[rem] + _dy[n] * rept;

    int dif_x = (llabs(_x - dx));
    int dif_y = (llabs(_y - dy));

    if (dif_x + dif_y <= dys)
    {
        return true;
    }

    return false;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int x1, x2, y1, y2, n;
    string str;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n >> str;

    int dx = 0, dy = 0, n_x = x2 - x1, n_y = y2 - y1;

    fr(i, 0, n)
    {
        if (str[i] == 'U')
        {
            dy++;
        }
        else if (str[i] == 'D')
        {
            dy--;
        }
        else if (str[i] == 'L')
        {
            dx--;
        }
        else if (str[i] == 'R')
        {
            dx++;
        }

        _dx[i + 1] = dx;
        _dy[i + 1] = dy;
    }

    int l = 0, h = inf;

    while (l <= h)
    {
        int m = (l + h) / 2;
        if (!solve(m, n_x, n_y, n))
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }

    if (l >= inf)
    {
        cout << -1;
    }
    else
    {
        cout << l;
    }

    return 0;
}
