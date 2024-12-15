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

int a[2][1001][1001], ind[1001][1001], chk[1001][1001];

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        fr(l, 0, 2)
        {
            fr(i, 0, n)
            {
                string str;
                cin >> str;

                fr(j, 0, n)
                {
                    a[l][i][j] = (int)(str[j] - '0');
                }
            }
        }

        si r, c;
        fr(i, 0, n)
        {
            fr(j, 0, n)
            {
                ind[i][j] = (a[0][i][j] != a[1][i][j]);

                if (ind[i][j] == 0)
                {
                    r.insert(i);
                    c.insert(j);
                }

                chk[i][j] = 0;
            }
        }

        for (auto u : r)
        {
            fr(i, 0, n)
            {
                chk[u][i] = 1 - chk[u][i];
            }
        }

        for (auto u : c)
        {
            fr(i, 0, n)
            {
                chk[i][u] = 1 - chk[i][u];
            }
        }

        bool isPos = true;
        fr(i, 0, n)
        {
            fr(j, 0, n)
            {
                if (chk[i][j] != a[1][i][j])
                {
                    isPos = false;
                }
            }
        }

        // fr(i, 0, n)
        // {
        //     fr(j, 0, n)
        //     {
        //         cout << ind[i][j];
        //     }
        //     cout << endl;
        // }

        // fr(i, 0, n)
        // {
        //     fr(j, 0, n)
        //     {
        //         cout << chk[i][j];
        //     }
        //     cout << endl;
        // }

        cout << (isPos ? "YES" : "NO") << "\n";
    }
    return 0;
}
