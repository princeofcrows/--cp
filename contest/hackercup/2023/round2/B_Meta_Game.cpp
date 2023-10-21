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

// Const
#define mod 875168479
// 28722900390631
#define inf 1e18 + 19
#define mx 6000005
#define pi acos(-1.0)
int seed = 997;
int z[] = {997, 769, 919, 647, 839};

// Input Output
#define sild(x) scanf("%lld", &x)
#define sid(x) scanf("%d", &x)
#define rin() freopen("meta_game_input.txt", "r", stdin)
#define wrout() freopen("out_b.txt", "w", stdout)
#define fst                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// Loops
#define fr(i, s, e) for (int i = s; i < e; i++)
#define ifr(i, s, e) for (int i = s; i <= e; i++)
#define rfr(i, e, s) for (int i = e - 1; i >= s; i--)

// Functions
ll gcd(ll a, ll b)
{
    return b ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
// bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

// random
// mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

int a[mx], b[mx], p[2][mx];

int bigmod(int a, int b)
{
    if (!b)
    {
        return 1;
    }

    int c = bigmod(a, b / 2);
    c = (c * c) % mod;

    if (b % 2)
    {
        c = (c * a) % mod;
    }

    return c;
}

void gen(int n)
{
    int base = p[0][0] = p[1][0] = 1;

    fr(i, 0, 3 * n)
    {
        base = (base * seed) % mod;
        p[0][i + 1] = base;
        p[1][i + 1] = bigmod(base, mod - 2);
    }
}

int for_hash(int n)
{
    int base = 1, h = 0;

    fr(i, 0, n)
    {
        h = (h + base * a[i]) % mod;
        base = (base * seed) % mod;
    }

    return h;
}

int rev_hash(int n)
{
    int h = 0;

    fr(i, 0, n)
    {
        h = (h * seed + b[i]) % mod;
    }

    return h;
}

bool check(int n, int offset)
{
    int l = n / 2;
    int h = l + 1 + n % 2;

    fr(i, 0, l)
    {
        int j = (i + offset);
        if (a[j] >= b[j])
        {
            return false;
        }
    }

    fr(i, h, n)
    {
        int j = (i + offset);
        if (a[j] <= b[j])
        {
            return false;
        }
    }

    fr(i, 0, n)
    {
        int j = n - 1 - i;

        if (a[i + offset] != b[j + offset])
        {
            return false;
        }
    }

    return true;
}

int add(int a, int b)
{
    return (a + b) % mod;
}

int sub(int a, int b)
{
    return (a - b + mod) % mod;
}

int mul(int a, int b)
{
    return (a * b) % mod;
}

int pro_a(int ah, int i, int n)
{
    int x = sub(ah, a[i]);
    int n_v = mul(a[i + n], p[0][n - 1]);

    x = mul(x, p[1][1]);
    x = add(x, n_v);

    return x;
}

int pro_b(int bh, int i, int n)
{
    int o_v = mul(b[i], p[0][n - 1]);
    int x = sub(bh, o_v);
    int n_v = b[i + n];

    x = mul(x, p[0][1]);
    x = add(x, n_v);

    return x;
}

int solve(int n)
{
    fr(i, n, 2 * n) a[i] = b[i - n];
    fr(i, n, 2 * n) b[i] = a[i - n];

    fr(i, 2 * n, 3 * n) a[i] = a[i - 2 * n];
    fr(i, 2 * n, 3 * n) b[i] = b[i - 2 * n];

    int ah = for_hash(n);
    int bh = rev_hash(n);

    int j = n;
    fr(i, 0, 2 * n + 1)
    {
        if (ah == bh)
        {

            if (check(n, i))
            {
                return i;
            }
        }

        ah = pro_a(ah, i, n);
        bh = pro_b(bh, i, n);
        // cout << ah << " " << bh << endl;
    }

    return -1;
}

int sol(int n)
{

    int x;

    si s;
    mii mp;
    for (int i = 0; i < 5; i++)
    {
        seed = z[i];
        // cout << seed << endl;
        gen(n);
        x = solve(n);
        // cout << x << endl;

        s.insert(x);
        mp[x]++;
    }

    int res = x, m = mp[x];

    for (auto u : s)
    {
        if (mp[u] > m)
        {
            m = mp[u];
            x = u;
        }
    }

    return x;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t, cs = 1;
    sild(t);

    while (t--)
    {
        int n;
        sild(n);

        fr(i, 0, n) sild(a[i]);
        fr(i, 0, n) sild(b[i]);

        cout << "Case #" << cs++ << ": " << sol(n) << endl;

        // cout << n << endl;
        // fr(i, 0, n) cout << 1 << " ";
        // cout << endl;
        // fr(i, 0, n) cout << 1 << " ";
        // cout << endl;
    }
    return 0;
}
