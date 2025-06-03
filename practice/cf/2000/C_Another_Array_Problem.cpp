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

int ara[MX];

int getMax(int n)
{
    int ans = 0;
    fr(i, 0, n) ans = max(ans, ara[i]);
    return ans;
}

bool isNotCorner(int n)
{
    int _max = getMax(n);

    fr(i, 0, n)
    {
        if (ara[i] == _max && i != 1 && i != n - 2)
        {
            return true;
        }
    }

    return false;
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
        int n, tot = 0;
        cin >> n;

        fr(i, 0, n)
        {
            cin >> ara[i];
            tot += ara[i];
        }

        if (n == 1)
        {
            cout << tot << endl;
        }
        else if (n == 2)
        {
            int x = llabs(ara[0] - ara[1]) * 2LL;
            cout << max(x, tot) << endl;
        }
        else if (n == 3)
        {
            if (isNotCorner(n))
            {
                cout << getMax(n) * 3 << endl;
                continue;
            }

            int _min = min(ara[0], ara[2]);
            int rest = max(ara[0], ara[2]);
            int ans = max((getMax(n) - _min) * 3, tot);
            ans = max(ans, (getMax(n) - _min) * 2 + rest);
            ans = max(ans, 3 * rest);

            cout << ans << endl;
        }
        else
        {
            cout << getMax(n) * n << endl;
        }
    }
    return 0;
}
