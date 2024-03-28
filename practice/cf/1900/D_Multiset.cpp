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

// Const
#define mod 1000000007
// 28722900390631
#define inf 1e18 + 19
// #define mx 2097152
#define pi acos(-1.0)
#define seed 997
// 769 919 647 839

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

const int mx = (1 << 20);
int tree[mx + 5];

int read(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val)
{
    while (idx <= mx)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int bs_on_bit(int val)
{
    int idx = 0, d = mx, tidx;
    val--;
    while (d > 0 && idx <= mx)
    {
        tidx = idx + d;
        if (tidx <= mx && tree[tidx] <= val)
        {
            idx = tidx;
            val -= tree[tidx];
        }
        d >>= 1;
    }

    return idx + 1;
}

int32_t main()
{
    // rin();
    // wrout();
    // fst;

    int n, q;
    sid(n);
    sid(q);
    mem(tree, 0);

    int a;
    fr(i, 0, n)
    {
        sid(a);
        update(a, 1);
    }

    int k;
    fr(i, 0, q)
    {
        sid(k);

        if (k > 0)
        {
            update(k, 1);
        }
        else
        {
            int idx = bs_on_bit(-k);

            update(idx, -1);
        }
    }

    fr(i, 1, n + 1)
    {
        if (read(i) > 0)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
