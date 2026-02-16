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

int a[3003], b[3003], c[3003], id[3003], dp[2][3003];

bool dontInter(int i, int j)
{
    if (a[i] == a[j] && b[i] == b[j] && c[i] != c[j])
    {
        return true;
    }

    int x = (b[i] - b[j]) * (b[i] - b[j]) - 4 * (a[i] - a[j]) * (c[i] - c[j]);

    return x < 0;
}

bool comp(int a, int b)
{
    return c[a] < c[b];
}

void solve(int n, int idx)
{
    fr(i, 0, n)
    {
        fr(j, i + 1, n)
        {
            if (dontInter(id[i], id[j]))
            {
                dp[idx][id[j]] = max(dp[idx][id[j]], dp[idx][id[i]] + 1);
            }
        }
    }
}

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
        int n;
        cin >> n;
        fr(i, 0, n)
        {
            cin >> a[i] >> b[i] >> c[i];
            id[i] = i;

            dp[0][i] = dp[1][i] = 0;
        }

        sort(id, id + n, comp);

        solve(n, 0);
        reverse(id, id + n);
        solve(n, 1);

        fr(i, 0, n) cout << dp[0][i] + 1 + dp[1][i] << " ";
        cout << endl;
    }
    return 0;
}
