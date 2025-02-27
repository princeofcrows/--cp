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
#define mod 1000000007
// 28722900390631
#define inf 1e18 + 19
#define mx 200015
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

vi divs[mx];
int a[mx], b[mx];
bool isPos[2][mx];

void generateDivs()
{
    fr(i, 1, mx)
    {
        for (int j = i; j < mx; j += i)
        {
            divs[j].pb(i);
        }
    }
}

int32_t main()
{
    // rin();
    // wrout();
    fst;
    generateDivs();
    mem(isPos, false);

    int n, m, q, sumR = 0, sumC = 0;
    cin >> n >> m >> q;

    fr(i, 0, n)
    {
        cin >> a[i];
        sumR += a[i];
    };

    fr(i, 0, m)
    {
        cin >> b[i];
        sumC += b[i];
    };

    si c, r;
    fr(i, 0, n)
    {
        r.insert(sumR - a[i]);
        // cout << sumR - a[i] << " ";
    }
    // cout << endl;
    fr(i, 0, m)
    {
        c.insert(sumC - b[i]);
        // cout << sumC - b[i] << " ";
    }

    fr(i, 1, mx)
    {
        for (auto u : divs[i])
        {
            int v = i / u;

            if (r.count(u) && c.count(v))
            {
                isPos[0][i] = true;
            }

            if (r.count(-u) && c.count(-v))
            {
                isPos[0][i] = true;
            }

            if (r.count(-u) && c.count(v))
            {
                isPos[1][i] = true;
            }

            if (r.count(u) && c.count(-v))
            {
                isPos[1][i] = true;
            }
        }
    }

    while (q--)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            (isPos[0][x] ? yes() : no());
        }
        else
        {
            (isPos[1][-x] ? yes() : no());
        }
    }

    return 0;
}
