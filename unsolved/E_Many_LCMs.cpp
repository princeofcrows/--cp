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
const int mod = 998244353;
// 28722900390631
const int inf = 1e18 + 19;
const int MX = 100002;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

bool isPrime[MX];
int cur[MX];
vi s[MX];
mii mp[MX];

ll frd[200005], bck[200005], a[200005];

void seive()
{
    mem(isPrime, true);
    fr(i, 1, MX) cur[i] = i;
    fr(i, 2, MX)
    {
        if (isPrime[i])
        {
            for (int j = i; j < MX; j += i)
            {
                isPrime[j] = false;
                s[j].pb(i);
                while (cur[j] % i == 0)
                {
                    cur[j] /= i;
                    mp[j][i]++;
                }
            }
        }
    }
}

long long binPowRec(long long a, long long b)
{
    if (b == 0)
        return 1;

    long long res = binPowRec(a, b / 2);

    if (b % 2)
    {
        return (((res * res) % mod) * a) % mod;
    }
    else
    {
        return (res * res) % mod;
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

    seive();
    while (t--)
    {
        int n;
        cin >> n;

        fr(i, 0, n)
        {
            cin >> a[i];
        }

        mii _mp;
        ll l = 1;
        frd[0] = 1;
        fr(i, 0, n)
        {

            for (auto u : s[a[i]])
            {
                int need = mp[a[i]][u];
                int have = _mp[u];

                while (have < need)
                {
                    l = (l * u) % mod;
                    have++;
                }

                _mp[u] = have;
            }

            frd[i + 1] = l;
        }

        _mp.clear();
        l = 1;
        bck[n + 1] = 1;
        rfr(i, n, 0)
        {
            for (auto u : s[a[i]])
            {
                int need = mp[a[i]][u];
                int have = _mp[u];

                while (have < need)
                {
                    l = (l * u) % mod;
                    have++;
                }

                _mp[u] = have;
            }

            bck[i + 1] = l;
        }

        ifr(i, 1, n)
        {
            ll g = gcd(frd[i - 1], bck[i + 1]);
            g = binPowRec(g, mod - 2);
            ll ans = (frd[i - 1] * bck[i + 1]) % mod;
            cout << (ans * g) % mod << " ";
        }

        cout << endl;
    }
    return 0;
}
