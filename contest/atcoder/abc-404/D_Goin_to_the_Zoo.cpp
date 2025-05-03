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
int Set(int N, int pos) { return N = N | (1LL << pos); }
int reset(int N, int pos) { return N = N & ~(1LL << pos); }
bool check(int N, int pos) { return (bool)(N & (1LL << pos)); }
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

int c[14];
vi a[14];
int vis[1200][101], cost[1200];

void checkAll(int n, int m, int mask)
{
    int cnt = 0, tot = 0;

    fr(i, 0, n)
    {
        if (check(mask, i))
        {
            for (auto u : a[i])
            {
                vis[mask][u]++;
            }

            tot += c[i];
        }
    }

    cost[mask] = tot;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n, m;
    cin >> n >> m;
    fr(i, 0, n)
    {
        cin >> c[i];
    }

    fr(i, 0, m)
    {
        int k;
        cin >> k;

        fr(j, 0, k)
        {
            int x;
            cin >> x;
            a[x - 1].pb(i);
        }
    }

    int ans = inf;
    for (int i = 0; i < (1LL << n); i++)
    {
        checkAll(n, m, i);
    }

    for (int i = 0; i < (1LL << n); i++)
    {
        for (int j = 0; j < (1LL << n); j++)
        {
            bool isOk = true;
            for (int l = 0; l < m; l++)
            {
                if (vis[i][l] + vis[j][l] < 2)
                {
                    isOk = false;
                    break;
                }
            }

            if (isOk)
            {
                ans = min(ans, cost[i] + cost[j]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
