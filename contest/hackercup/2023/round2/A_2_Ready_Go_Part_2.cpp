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
#define mod 875168479
// 28722900390631
#define inf 1e18 + 19
#define mx 9000005
#define pi acos(-1.0)
int seed = 997;
int z[] = {997, 769, 919, 647, 839};

// Input Output
#define sild(x) scanf("%lld", &x)
#define sid(x) scanf("%d", &x)
#define rin() freopen("ready_go_part_2_input.txt", "r", stdin)
#define wrout() freopen("out_a2.txt", "w", stdout)
#define fst                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// Loops
#define fr(i, s, e) for (int i = s; i < e; i++)
#define ifr(i, s, e) for (int i = s; i <= e; i++)
#define rfr(i, e, s) for (int i = e - 1; i >= s; i--)

// Functions
ll gcd(ll a, ll b)
{
    return b ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
int Set(int N, int pos)
{
    return N = N | (1 << pos);
}
int reset(int N, int pos)
{
    return N = N & ~(1 << pos);
}
// bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes()
{
    cout << "YES\n";
}
void no()
{
    cout << "NO\n";
}

// random
// mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

string g[3005];
bool vis[3005][3005];

set<pii> s[mx];
int tot[mx];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void init(int r, int c)
{
    ifr(i, 0, r * c)
    {
        s[i].clear();
        tot[i] = 0;
    }

    ifr(i, 0, r) ifr(j, 0, c) vis[i][j] = false;
}

void dfs(int i, int j, int r, int c, int cnt)
{

    vis[i][j] = true;
    tot[cnt]++;

    fr(l, 0, 4)
    {
        int x = dx[l] + i;
        int y = dy[l] + j;

        if (x >= 0 && x < r)
        {
            if (y >= 0 && y < c)
            {
                if (g[x][y] == '.')
                {
                    s[cnt].insert(make_pair(x, y));
                }
                else if (g[x][y] == 'W' && !vis[x][y])
                {
                    dfs(x, y, r, c, cnt);
                }
            }
        }
    }
}

int solve(int r, int c)
{
    init(r, c);
    int cnt = 0;

    fr(i, 0, r) fr(j, 0, c)
    {
        if (g[i][j] == 'W' && !vis[i][j])
        {
            dfs(i, j, r, c, cnt);
            cnt++;
        }
    }

    map<pii, int> mp;
    int ans = 0;

    fr(i, 0, cnt)
    {
        if (s[i].size() == 1)
        {
            pii p = *(s[i].begin());
            mp[p] += tot[i];
            ans = max(ans, mp[p]);
        }
    }

    return ans;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t, cs = 1;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        // cout << r << " " << c << endl;

        fr(i, 0, r)
        {
            cin >> g[i];
        }
        // cout << r << c << endl;

        // printf("Case #%d: %d\n", cs++, solve(r, c));
        // if (cs == 5)
        // {
        //     cs++;
        //     continue;
        // }
        cout << "Case #" << cs++ << ": " << solve(r, c) << endl;
    }
    return 0;
}
