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
#define mx 5000015
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

const int limit = 10000005;
int v[limit];
int ara[mx];
vi res[2];

void gen()
{
    mem(v, -1);

    fr(i, 2, limit)
    {
        if (v[i] == -1)
        {
            for (int j = i; j < limit; j += i)
            {
                v[j] = i;
            }
        }
    }
}

void solve(int x)
{
    int u = v[x];
    while (x % u == 0)
    {
        x /= u;
    }

    if (x == 1)
    {
        res[0].pb(-1);
        res[1].pb(-1);
        return;
    }
    res[0].pb(x);
    res[1].pb(u);
}

int32_t main()
{
    // rin();
    // wrout();
    // fst;
    gen();

    int n;
    sid(n);

    fr(i, 0, n)
    {

        sid(ara[i]);
        solve(ara[i]);
    }

    for (int j = 0; j < 2; j++)
    {
        for (auto u : res[j])
        {
            printf("%d ", u);
        }
        printf("\n");
    }
    return 0;
}
