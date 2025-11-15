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

int n[3], col[3][MX];

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        fr(i, 0, 3)
        {
            cin >> n[i];
        }

        fr(i, 0, 3)
        {
            fr(j, 0, n[i])
            {
                cin >> col[i][j];
            }

            sort(col[i], col[i] + n[i]);
        }

        si s;
        unsigned long long ans = inf * 4;
        fr(i, 0, 3)
        {
            fr(ii, 0, 3) s.insert(ii);
            s.erase(i);

            fr(j, 0, n[i])
            {
                int st[3], en[3];
                vi v;

                for (auto u : s)
                {
                    int lo = lower_bound(col[u], col[u] + n[u], col[i][j]) - col[u];
                    st[u] = max(0LL, lo - 5);
                    en[u] = min(n[u] - 1LL, lo + 5);
                    v.pb(u);
                }

                ifr(l, st[v[0]], en[v[0]])
                {
                    ifr(k, st[v[1]], en[v[1]])
                    {
                        unsigned long long x = (col[i][j] - col[v[0]][l]) * (col[i][j] - col[v[0]][l]);
                        unsigned long long y = (col[i][j] - col[v[1]][k]) * (col[i][j] - col[v[1]][k]);
                        unsigned long long z = (col[v[1]][k] - col[v[0]][l]) * (col[v[1]][k] - col[v[0]][l]);

                        ans = min(ans, x + y + z);
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
