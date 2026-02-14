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

mii mp[2];
si _h[MX], _w[MX];
int h[MX], w[MX];
pii res[MX];
int H, W;

void solve(int x, int y)
{
    if (x > H && y > W)
    {
        return;
    }

    int cur_h = H - x + 1;
    int cur_w = W - y + 1;

    int id_h = mp[0][cur_h];
    int id_w = mp[1][cur_w];

    if (id_h && !_h[id_h].empty())
    {
        int idx = (*_h[id_h].begin());
        _h[id_h].erase(idx);
        _w[mp[1][w[idx]]].erase(idx);

        res[idx] = {x, y};
        solve(x, y + w[idx]);
    }
    else if (id_w && !_w[id_w].empty())
    {
        int idx = (*_w[id_w].begin());
        _w[id_w].erase(idx);
        _h[mp[0][h[idx]]].erase(idx);

        res[idx] = {x, y};
        solve(x + h[idx], y);
    }
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n;

    cin >> H >> W >> n;

    int id_h = 1, id_w = 1;

    fr(i, 0, n)
    {
        cin >> h[i] >> w[i];

        if (!mp[0][h[i]])
        {
            mp[0][h[i]] = id_h++;
        }

        if (!mp[1][w[i]])
        {
            mp[1][w[i]] = id_w++;
        }

        _h[mp[0][h[i]]].insert(i);
        _w[mp[1][w[i]]].insert(i);
    }

    solve(1, 1);

    fr(i, 0, n) cout << res[i].fi << " " << res[i].se << "\n";
    return 0;
}
