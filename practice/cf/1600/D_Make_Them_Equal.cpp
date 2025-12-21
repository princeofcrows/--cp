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

int b[MX], c[MX], a[MX], dp[MX * 10], bfs[1005];

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    mem(bfs, 0);
    queue<pii> q;
    q.push({1, 1});
    bfs[1] = 1;

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        ifr(i, 1, p.first)
        {
            int x = p.first / i + p.fi;
            if (x > 1000)
            {
                continue;
            }

            if (!bfs[x])
            {
                bfs[x] = p.se + 1;
                q.push({x, bfs[x]});
            }
        }
    }

    while (t--)
    {
        int n, k, tot = 0;
        cin >> n >> k;

        fr(i, 0, n)
        {
            cin >> b[i];
            a[i] = bfs[b[i]] - 1;
            tot += a[i];
        }

        k = min(k, tot);

        fr(i, 0, n) cin >> c[i];
        ifr(i, 0, k) dp[i] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = k; j >= a[i - 1]; j--)
            {
                dp[j] = max(dp[j], dp[j - a[i - 1]] + c[i - 1]);
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}
