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

vpi v;

pii arr[MX];
pii tree[MX * 3];
vi r;

void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = min(tree[Left], tree[Right]);
}
pii query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return {inf, -1};
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    auto p1 = query(Left, b, mid, i, j);
    auto p2 = query(Right, mid + 1, e, i, j);
    return min(p1, p2);
}
void update(int node, int b, int e, int i, pii newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i)
    {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = min(tree[Left], tree[Right]);
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n, m;
    cin >> n >> m;

    fr(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort_all(v);

    for (int i = 0; i < m; i++)
    {
        arr[i + 1] = {v[i].fi - v[i].se, i + 1};
        r.pb(v[i].fi);
    }

    init(1, 1, m);

    int ans = 0;
    while (n > 0)
    {

        int idx = upper_bound(r.begin(), r.end(), n) - r.begin();
        if (idx == 0)
        {
            break;
        }

        auto p = query(1, 1, m, 1, idx);

        // cout << p.fi << " " << p.se << " " << idx << endl;
        if (p.first > n)
        {
            break;
        }

        int a = v[p.se - 1].first;
        int red = max((n - a), p.fi);
        int inc = red / p.fi;

        ans += inc;
        n = (n - inc * p.fi);
        // update(1, 1, m, p.second, {inf, p.se});
    }

    cout << ans << endl;
    return 0;
}
