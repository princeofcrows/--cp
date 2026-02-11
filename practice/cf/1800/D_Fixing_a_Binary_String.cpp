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

string s;
int frd[MX], bck[MX], pSeed[MX];

int genHash(int n, int k)
{
    int now = (int)(s[0]);
    int otherNow = s[0] == '1' ? '0' : '1';
    int hash = 0, cur = 0, base = 1;

    fr(i, 0, n)
    {
        hash = (hash + now * base) % mod;
        base = (base * seed) % mod;
        cur++;

        if (cur == k)
        {
            cur = 0;
            swap(now, otherNow);
        }
    }

    return hash;
}

void createHashArray(int n)
{
    int hash = 0, base = 1;
    fr(i, 0, n)
    {
        hash = (hash + ((int)(s[i])) * base) % mod;
        base = (base * seed) % mod;
        frd[i] = hash;
    }

    hash = 0, base = 1;
    rfr(i, n, 0)
    {

        hash = (hash + ((int)(s[i])) * base) % mod;
        base = (base * seed) % mod;
        bck[i] = hash;
    }
}

int getPoSeed(int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (pSeed[n] != -1)
    {
        return pSeed[n];
    }

    return pSeed[n] = (seed * getPoSeed(n - 1)) % mod;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    mem(pSeed, -1);
    while (t--)
    {
        int k, n;
        cin >> n >> k;

        cin >> s;

        int hash = genHash(n, k);
        // cout << hash << endl;
        bool happened = false;

        createHashArray(n);

        fr(i, 0, n - 1)
        {
            int a = frd[i];
            int b = bck[i + 1];

            int isHash = (a + b * getPoSeed(i + 1)) % mod;
            // cout << isHash << " " << hash << endl;

            if (isHash == hash)
            {
                cout << i + 1 << endl;
                happened = true;
                break;
            }
        }

        if (!happened)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
