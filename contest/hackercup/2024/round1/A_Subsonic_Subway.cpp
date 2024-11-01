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
#define mx 2000015
#define pi acos(-1.0)
#define seed 997
// 769 919 647 839

// Input Output
#define sild(x) scanf("%lld", &x)
#define sid(x) scanf("%d", &x)
#define rin() freopen("subsonic_subway_input.txt", "r", stdin)
#define wrout() freopen("subsonic_subway_output.txt", "w", stdout)
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

double a[mx], b[mx];
double minSpeed[mx], maxSpeed[mx];

int32_t main()
{
    rin();
    wrout();
    fst;

    int t, cs = 1;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        double minX = 0.0, maxX = inf;
        fr(i, 1, n + 1)
        {
            cin >> a[i] >> b[i];
            maxSpeed[i] = (i * 1.0) / (a[i] + 0.00000000000001);
            minSpeed[i] = (i * 1.0) / (b[i] + 0.00000000000001);

            minX = max(minX, minSpeed[i]);
            maxX = min(maxX, maxSpeed[i]);
        }

        if (maxX < minX)
        {
            cout << "Case #" << cs++ << ": " << -1 << endl;
        }
        else
        {
            cout << fixed;
            cout << setprecision(10);
            cout << "Case #" << cs++ << ": " << minX << endl;
        }
    }
    return 0;
}
