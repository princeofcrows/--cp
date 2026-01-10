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
const int MX = 100015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

int dis[2][MX];
vi g[MX];

int findFurthestVertex(int idx, int n)
{
    int _d = -1, res = -1;
    ifr(i, 1, n)
    {
        if (dis[idx][i] > _d)
        {
            _d = dis[idx][i];
            res = i;
        }
    }

    return res;
}

void dfs(int u, int p, int lev, int idx)
{
    dis[idx][u] = lev;
    for (auto v : g[u])
    {
        if (v == p)
        {
            continue;
        }

        dfs(v, u, lev + 1, idx);
    }
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n;
    cin >> n;

    fr(i, 1, n)
    {
        int a, b;
        cin >> a >> b;

        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1, 0, 0, 0);
    int v1 = findFurthestVertex(0, n);

    dfs(v1, 0, 0, 0);
    int v2 = findFurthestVertex(0, n);
    dfs(v2, 0, 0, 1);

    priority_queue<pii, vpi, greater<pii>> q;
    ifr(i, 1, n)
    {
        q.push({max(dis[0][i], dis[1][i]), i});
    }

    int tot = 1;

    ifr(i, 1, n)
    {
        while (!q.empty() && q.top().first < i)
        {
            // cout << i << " " << q.top().first << " " << q.top().second << endl;
            q.pop();
            tot++;

            if (tot > n)
            {
                tot--;
            }
        }

        cout << tot << " ";
    }
    return 0;
}
