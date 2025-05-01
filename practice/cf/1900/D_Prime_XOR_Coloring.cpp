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

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n, e_f = 0, o_f = 0;
        vi res;
        si cnt;

        cin >> n;

        if (n == 2)
        {
            cout << "2\n1 2\n";
            continue;
        }
        else if (n == 3)
        {
            cout << "2\n1 2 2\n";
            continue;
        }
        else if (n == 4)
        {
            cout << "3\n1 2 2 3\n";
            continue;
        }
        else if (n == 5)
        {
            cout << "3\n1 2 2 3 3\n";
            continue;
        }

        ifr(i, 1, n)
        {
            if (i % 2)
            {
                if (!o_f)
                {
                    res.pb(1);
                }
                else
                {
                    res.pb(2);
                }

                o_f = 1 - o_f;
            }
            else
            {
                if (!e_f)
                {
                    res.pb(3);
                }
                else
                {
                    res.pb(4);
                }

                e_f = 1 - e_f;
            }

            cnt.insert(res.back());
        }

        cout << cnt.size() << endl;
        for (auto u : res)
        {
            cout << u << " ";
        }

        cout << endl;
    }
    return 0;
}
