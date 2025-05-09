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
const int mod = 1000000007;
// 28722900390631
const int inf = 1e18 + 19;
const int MX = 300015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

int a[MX][8];
mii mp;
vi v;

bool is_pos(int val, int n, int m, bool pr = false)
{
    int lim = 1 << m;
    vi rec[lim];

    fr(i, 0, n)
    {
        int mask = 0;
        fr(j, 0, m)
        {
            if (a[i][j] >= val)
            {
                mask = Set(mask, j);
            }
        }

        rec[mask].pb(i + 1);
    }

    fr(i, 0, (lim))
    {
        fr(j, 0, (lim))
        {
            if ((i | j) == (lim - 1))
            {
                if (rec[i].size() != 0 && rec[j].size() != 0)
                {
                    if (pr)
                    {
                        cout << rec[i].front() << " " << rec[j].front();
                    }
                    return true;
                }
            }
        }
    }

    return false;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n, m;
    cin >> n >> m;

    fr(i, 0, n)
    {
        fr(j, 0, m)
        {
            cin >> a[i][j];

            if (!mp[a[i][j]])
            {
                v.push_back(a[i][j]);
                mp[a[i][j]] = 1;
            }
        }
    }

    sort_all(v);

    int l = 0, h = v.size() - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (is_pos(v[mid], n, m))
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    is_pos(v[h], n, m, true);

    return 0;
}
