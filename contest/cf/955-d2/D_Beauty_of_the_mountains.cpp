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

int h[505][505];
int g[505][505], sum[505][505];
si st;

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        fr(i, 0, n)
        {
            fr(j, 0, m)
            {
                cin >> h[i][j];
            }
        }

        int a = 0, b = 0;
        fr(i, 0, n)
        {
            string s;
            cin >> s;

            fr(j, 0, m)
            {
                g[i][j] = (int)(s[j] - '0');

                if (g[i][j])
                {
                    a += h[i][j];
                }
                else
                {
                    b += h[i][j];
                }

                g[i][j] = (g[i][j] ? 1 : -1);
                sum[i][j] = 0;
            }
        }

        fr(j, 0, m)
        {
            sum[0][j] = g[0][j];
        }

        fr(i, 1, n)
        {
            fr(j, 0, m)
            {
                sum[i][j] = g[i][j] + sum[i - 1][j];
            }
        }

        fr(i, 0, n)
        {
            fr(j, 1, m)
            {
                sum[i][j] += sum[i][j - 1];
            }
        }

        fr(i, 0, n)
        {
            fr(j, 0, m)
            {
                int rx = i + k - 1;
                int ry = j + k - 1;

                if (rx >= n || ry >= m)
                {
                    continue;
                }

                int res = sum[rx][ry];
                if (i - 1 >= 0)
                {
                    res -= sum[i - 1][ry];
                }
                if (j - 1 >= 0)
                {
                    res -= sum[rx][j - 1];
                }

                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    res += sum[i - 1][j - 1];
                }

                // cout << i << " " << j << " " << res << endl;
                res = llabs(res);

                if (res)
                {
                    st.insert(res);
                }
            }
        }

        int d = llabs(a - b), gc = -1;
        bool isPos = false;
        // cout << a << " " << b << " " << d << endl;

        for (auto u : st)
        {
            if (gc == -1)
            {
                gc = u;
            }
            else
            {
                gc = gcd(u, gc);
            }
        }

        if (gc != -1 && d % gc == 0)
        {
            isPos = true;
        }

        if (isPos || d == 0)
        {
            yes();
        }
        else
        {
            no();
        }
        st.clear();
    }
    return 0;
}
