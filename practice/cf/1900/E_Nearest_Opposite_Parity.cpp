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

int a[MX], res[MX];
vi g[MX];

int32_t main()
{
    // rin();
    // wrout();
    fst;
    int n;
    cin >> n;

    ifr(i, 1, n)
    {
        cin >> a[i];
    }

    mem(res, -1);
    queue<int> q;
    ifr(i, 1, n)
    {
        bool is_rlx = false;
        int right_v = i - a[i];
        if (right_v >= 1 && a[i] % 2 != a[right_v] % 2)
        {
            res[i] = 1;

            is_rlx = true;
        }

        int left_v = i + a[i];
        if (left_v <= n && a[i] % 2 != a[left_v] % 2)
        {
            res[i] = 1;

            is_rlx = true;
        }

        if (is_rlx)
        {
            q.push(i);
        }

        if (right_v >= 1)
            g[right_v].push_back(i);
        if (left_v <= n)
            g[left_v].push_back(i);
    }

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto u : g[v])
        {
            if (res[u] == -1)
            {
                res[u] = res[v] + 1;
                q.push(u);
            }
        }
    }

    ifr(i, 1, n) cout << res[i] << " ";

    return 0;
}
