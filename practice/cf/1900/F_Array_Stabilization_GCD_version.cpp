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

#define MAXN 400005
#define K 22

int table[MAXN][K], ara[MAXN];

int callBackFn(int a, int b)
{
    return gcd(a, b);
}

void initSparseTable(int n)
{
    for (int i = 0; i < n; i++)
    {
        table[i][0] = ara[i];
    }

    for (int j = 1; j <= K; j++)
    {
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = callBackFn(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }
}

int query(int L, int R)
{
    int ans = 0;
    for (int j = K; j >= 0; j--)
    {
        if (L + (1 << j) - 1 <= R)
        {
            ans = callBackFn(ans, table[L][j]);
            L += 1 << j;
        }
    }
    return ans;
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
        int n, g;
        cin >> n;

        fr(i, 0, n)
        {
            cin >> ara[i];

            ara[i + n] = ara[i];

            if (i)
            {
                g = gcd(g, ara[i]);
            }
            else
            {
                g = ara[i];
            }
        }

        initSparseTable(2 * n);

        int ans = 0;
        fr(i, 0, n)
        {
            int l = i, h = 2 * n - 1;

            while (l <= h)
            {
                int m = (l + h) / 2;
                int x = query(i, m);

                if (x == g)
                {
                    h = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }

            ans = max(ans, l - i);
        }

        cout << ans << endl;
    }
    return 0;
}
