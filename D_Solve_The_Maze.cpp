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
void yes() { cout << "Yes\n"; }
void no() { cout << "No\n"; }

// Const
const int mod = 1000000007;
// 28722900390631
const int inf = 1e18 + 19;
const int MX = 200015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

string g[55];
bool isPos[55][55];
int dp[55][55];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isInside(int n, int m, int i, int j)
{
    return i >= 0 and j >= 0 and i < n and j < m;
}

bool bfs(int n, int m)
{

    queue<pii> q;

    if (isPos[n - 1][m - 1])
    {
        q.push({n - 1, m - 1});
        dp[n - 1][m - 1] = 1;
    }

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        fr(i, 0, 4)
        {
            int x = p.fi + dx[i];
            int y = p.se + dy[i];

            if (isInside(n, m, x, y) and dp[x][y] == -1 and isPos[x][y])
            {
                dp[x][y] = 1;
                q.push({x, y});
            }
        }
    }

    fr(i, 0, n)
    {
        fr(j, 0, m)
        {
            if (g[i][j] == 'G' and dp[i][j] == -1)
            {
                return false;
            }

            if (g[i][j] == 'B' and dp[i][j] == 1)
            {
                return false;
            }
        }
    }

    return true;
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
        int n, m;
        cin >> n >> m;

        fr(i, 0, n)
        {
            cin >> g[i];
            fr(j, 0, m)
            {
                isPos[i][j] = true;
                dp[i][j] = -1;
            }
        }

        fr(i, 0, n) fr(j, 0, m)
        {
            if (g[i][j] == 'B')
            {
                fr(l, 0, 4)
                {
                    int x = i + dx[l];
                    int y = j + dy[l];

                    if (isInside(n, m, x, y) and g[x][y] == '.')
                    {
                        isPos[x][y] = false;
                    }
                }
            }
            else if (g[i][j] == '#')
            {
                isPos[i][j] = false;
            }
        }

        (bfs(n, m) ? yes() : no());
    }
    return 0;
}
