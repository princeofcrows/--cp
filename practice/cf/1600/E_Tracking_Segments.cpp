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

int l[MX], r[MX];

#define MAXN 100005
#define K 22
using namespace std;

int table[MAXN][K], ara[MAXN];

int callBackFn(int a, int b)
{
    return max(a, b);
}

void initSparseTable(int n)
{
    for (int i = 0; i < n; i++)
    {
        table[i][0] = ara[i];
    }

    for (int j = 1; j <= K; j++)
    {
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = callBackFn(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }
}

int query(int L, int R)
{
    int ans = 0;
    for (int j = K; j >= 0; j--)
    {
        if (L + (1 << j) - 1 <= R)
        {
            ans = callBackFn(ans, table[L][j]);
            L += 1 << j;
        }
    }
    return ans;
}

bool checkValidity(int sz, int m, int q, vpi v)
{
    vi data;
    fr(i, 0, q) if (v[i].se <= sz) data.pb(v[i].fi);

    fr(i, 0, m)
    {
        int st = lower_bound(all(data), l[i]) - data.begin();
        int en = upper_bound(all(data), r[i]) - data.begin();

        if (en <= st)
        {
            continue;
        }

        int len = en - st;

        if (2 * len > r[i] - l[i] + 1)
        {
            return true;
        }
    }

    return false;
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

        fr(i, 0, m) cin >> l[i] >> r[i];

        int q;
        cin >> q;
        vpi v;

        fr(i, 0, q)
        {
            int x;
            cin >> x;
            v.pb({x, i + 1});
        }

        sort_all(v);
        fr(i, 0, q) ara[i] = v[i].se + 1;

        initSparseTable(q);
        int low = 1, high = q, ans = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (checkValidity(mid, m, q, v))
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
