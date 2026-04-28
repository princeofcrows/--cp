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
const int MX = 100015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

int a[MX];
string s;

struct treeNode
{
    int prop;
    int sum;
};

treeNode tree[2][8 * MX];

void init(int node, int b, int e, int idx)
{
    if (b == e)
    {
        if ((int)(s[b - 1] - '0') == idx)
        {
            tree[idx][node].sum = a[b];
        }
        else
        {
            tree[idx][node].sum = 0;
        }

        tree[idx][node].prop = 0;
        return;
    }

    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid, idx);
    init(Right, mid + 1, e, idx);

    tree[idx][node].sum = tree[idx][Left].sum ^ tree[idx][Right].sum;
    tree[idx][node].prop = 0;
}

void update(int node, int b, int e, int i, int j, int idx)
{
    if (tree[idx][node].prop != 0)
    {
        int tp = tree[idx][node].prop;

        tree[idx][node].prop = 0;
        tree[1 - idx][node].prop = 0;

        swap(tree[idx][node].sum, tree[1 - idx][node].sum);

        if (b != e)
        {
            tree[idx][node * 2].prop ^= tp;
            tree[idx][node * 2 + 1].prop ^= tp;

            tree[1 - idx][node * 2].prop ^= tp;
            tree[1 - idx][node * 2 + 1].prop ^= tp;
        }
    }
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        swap(tree[idx][node].sum, tree[1 - idx][node].sum);
        if (b != e)
        {
            tree[idx][node * 2].prop ^= 1;
            tree[idx][node * 2 + 1].prop ^= 1;

            tree[1 - idx][node * 2].prop ^= 1;
            tree[1 - idx][node * 2 + 1].prop ^= 1;
        }
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, idx);
    update(Right, mid + 1, e, i, j, idx);

    tree[idx][node].sum = tree[idx][Left].sum ^ tree[idx][Right].sum;
    tree[1 - idx][node].sum = tree[1 - idx][Left].sum ^ tree[1 - idx][Right].sum;
}

int query(int node, int b, int e, int i, int j, int idx)
{
    if (tree[idx][node].prop != 0)
    {
        int tp = tree[idx][node].prop;

        tree[idx][node].prop = 0;
        tree[1 - idx][node].prop = 0;

        swap(tree[idx][node].sum, tree[1 - idx][node].sum);

        if (b != e)
        {
            tree[idx][node * 2].prop ^= tp;
            tree[idx][node * 2 + 1].prop ^= tp;

            tree[1 - idx][node * 2].prop ^= tp;
            tree[1 - idx][node * 2 + 1].prop ^= tp;
        }
    }
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[idx][node].sum;

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    int p1 = query(Left, b, mid, i, j, idx);
    int p2 = query(Right, mid + 1, e, i, j, idx);

    return p1 ^ p2;
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
        int n;
        cin >> n;

        ifr(i, 1, n) cin >> a[i];
        cin >> s;

        init(1, 1, n, 0);
        init(1, 1, n, 1);

        int q;
        cin >> q;

        while (q--)
        {
            int tp;
            cin >> tp;

            if (tp == 1)
            {
                int l, r;
                cin >> l >> r;

                update(1, 1, n, l, r, 1);
            }
            else
            {
                int g;
                cin >> g;

                cout << query(1, 1, n, 1, n, g) << " ";
            }
        }

        cout << endl;
    }
    return 0;
}
