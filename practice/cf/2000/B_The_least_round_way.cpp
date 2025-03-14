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
    cin.tie(0);

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

const int divi[] = {2, 5};
int mat[1005][1005];
int val[2][1005][1005];
int dp[2][1005][1005];
string res;

void calc25(int n)
{
    mem(val, 0);

    fr(l, 0, 2)
    {
        fr(i, 0, n)
        {
            fr(j, 0, n)
            {
                int x = mat[i][j];

                while (x && (x % divi[l] == 0))
                {
                    val[l][i][j]++;
                    x /= divi[l];
                }
            }
        }
    }
}

int solve(int n, int i, int j, int idx)
{
    if (i >= n || j >= n)
    {
        return mod;
    }

    if (i == n - 1 && j == n - 1)
    {
        return val[idx][i][j];
    }

    if (dp[idx][i][j] != -1)
    {
        return dp[idx][i][j];
    }

    int d = solve(n, i + 1, j, idx) + val[idx][i][j];
    int r = solve(n, i, j + 1, idx) + val[idx][i][j];

    if (d <= r)
    {
        return dp[idx][i][j] = d;
    }

    return dp[idx][i][j] = r;
}

void path(int n, int i, int j, int idx)
{
    if (i == n - 1 && j == n - 1)
    {
        return;
    }

    int d = solve(n, i + 1, j, idx) + val[idx][i][j];
    int r = solve(n, i, j + 1, idx) + val[idx][i][j];

    if (d <= r)
    {
        res += "D";
        path(n, i + 1, j, idx);
        return;
    }

    res += "R";
    path(n, i, j + 1, idx);
}

int32_t main()
{
    // rin();
    // wrout();
    // fst;

    int n, x0, y0;
    sid(n);
    bool is0 = false;
    fr(i, 0, n)
    {
        fr(j, 0, n)
        {
            sid(mat[i][j]);
            if (!mat[i][j])
            {
                is0 = true;
                x0 = i;
                y0 = j;
            }
        }
    }

    calc25(n);
    mem(dp, -1);

    int ans2 = solve(n, 0, 0, 0);
    int ans5 = solve(n, 0, 0, 1);

    if (min(ans2, ans5) != 0 && is0)
    {
        cout << 1 << "\n";
        fr(i, 0, y0) cout << "R";
        fr(i, 0, n - 1) cout << "D";
        fr(i, y0, n - 1) cout << "R";
        return 0;
    }

    cout << min(ans2, ans5) << "\n";
    ans2 < ans5 ? path(n, 0, 0, 0) : path(n, 0, 0, 1);
    cout << res;
    return 0;
}
