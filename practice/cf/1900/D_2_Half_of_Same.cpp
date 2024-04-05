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
#define mx 200001
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

int a[44];

vi gen(int x)
{
    vi d;
    for (int j = 1; j * j <= (x); j += 1)
    {
        if (x % j == 0)
        {
            d.pb(j);
            d.pb(x / j);
        }
    }

    return d;
}

int32_t
main()
{
    // rin();
    // wrout();
    // fst;
    int t;
    sid(t);

    while (t--)
    {
        int n, ans = -1;
        sid(n);
        int h = n / 2;

        fr(i, 0, n)
        {
            sid(a[i]);
        }

        si s;
        fr(i, 0, n)
        {
            fr(j, i + 1, n)
            {
                int x = abs(a[i] - a[j]);
                if (x)
                {
                    for (auto u : gen(x))
                    {
                        s.insert(u);
                    }
                }
            }
        }

        s.insert(mod);
        s.insert(1);

        for (auto u : s)
        {
            if (u != 0)
            {
                mii m;
                fr(i, 0, n)
                {
                    int x = (a[i] % u + u) % u;
                    m[x]++;

                    if (m[x] >= h)
                    {
                        ans = max(ans, u);
                    }
                }
            }
        }

        if (ans == mod)
        {
            ans = -1;
        }

        printf("%d\n", ans);
    }
    return 0;
}
