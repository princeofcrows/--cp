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

si s;
map<int, int> mp[2];
int dp[2][MX];
int _x[MX];

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n, ax, bx, ay, by;
        cin >> n >> ax >> ay >> bx >> by;

        s.insert(ax);
        s.insert(bx);

        mp[0][ax] = ay;
        mp[1][ax] = ay;
        mp[0][bx] = by;
        mp[1][bx] = by;

        fr(i, 0, n)
        {
            cin >> _x[i];
            s.insert(_x[i]);
        }

        fr(i, 0, n)
        {
            int y;
            cin >> y;

            int x = _x[i];

            if (!mp[0][x])
                mp[0][x] = y;
            else
                mp[0][x] = min(mp[0][x], y);

            if (!mp[1][x])
                mp[1][x] = y;
            else
                mp[1][x] = max(mp[1][x], y);
        }

        int ans = bx - ax;
        int pre;

        int id = 0;
        for (auto x : s)
        {
            if (x == ax)
            {
                pre = x;

                dp[0][id] = ans;
                dp[1][id] = ans;

                id++;
                continue;
            }

            int dis = mp[1][x] - mp[0][x];

            // cout << "==========================" << endl;
            // cout << x << " ";
            // cout << dis << " " << endl;
            // cout << dp[0][id - 1] + llabs(mp[0][pre] - mp[1][x]) << " " << dp[1][id - 1] + llabs(mp[1][pre] - mp[1][x]) << endl;
            // cout << dp[0][id - 1] + llabs(mp[0][pre] - mp[0][x]) << " " << dp[1][id - 1] + llabs(mp[1][pre] - mp[0][x]) << endl;
            // cout << "==========================" << endl;

            dp[0][id] = min(dp[0][id - 1] + llabs(mp[0][pre] - mp[1][x]), dp[1][id - 1] + llabs(mp[1][pre] - mp[1][x])) + dis;
            dp[1][id] = min(dp[0][id - 1] + llabs(mp[0][pre] - mp[0][x]), dp[1][id - 1] + llabs(mp[1][pre] - mp[0][x])) + dis;

            id++;
            pre = x;
        }

        cout << min(dp[0][id - 1], dp[1][id - 1]) << "\n";
        s.clear();
        mp[0].clear();
        mp[1].clear();
    }
    return 0;
}
