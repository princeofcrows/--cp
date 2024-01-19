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
#define mx 1000005
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
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

vi d[mx];
int a[mx];

void pre()
{
    fr(i, 1, mx)
    {
        for (int j = i; j < mx; j += i)
        {
            d[i].pb(j);
        }
    }

    int ans = 0;
    rfr(i, mx, 1)
    {
        int cnt = 0, g = -1, taken = 0;
        for (auto u : d[i])
        {
            if (a[u] == 1)
            {
                cnt++;

                if (g == -1)
                {
                    g = u;
                }
                else
                {
                    g = gcd(u, g);
                }

                // cout << g << " " << u << endl;
            }
            else if (a[u] == u)
            {
                taken++;
            }
        }

        if (cnt >= 1 && !a[i] && g == i && taken + cnt > 1)
        {
            ans++;
            a[i] = 2;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    mem(a, 0);

    int n;
    cin >> n;

    fr(i, 0, n)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }

    pre();
    return 0;
}