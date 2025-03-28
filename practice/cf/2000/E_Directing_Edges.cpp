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

stack<int> stk;
int vis[MX], cy, pos[MX];
vector<int> g[MX], order[MX];
vpi edges;

int sizeSet[MX], parent[MX];

void initSet(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sizeSet[i] = 1;
    }
}

int findSet(int i)
{
    if (parent[i] == i)
        return i;

    return parent[i] = findSet(parent[i]);
}

bool isSameset(int i, int j)
{
    return (findSet(i) == findSet(j));
}

void unionSet(int i, int j)
{
    int a = findSet(j);
    int b = findSet(i);

    if (a == b)
        return;

    if (sizeSet[a] >= sizeSet[b])
    {
        sizeSet[a] += sizeSet[b];
        parent[b] = a;
    }
    else
    {
        sizeSet[b] += sizeSet[a];
        parent[a] = b;
    }
}

void topoSort(int u)
{
    if (vis[u])
    {
        if (vis[u] == 1)
            cy = true;
        return;
    }
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++)
    {
        unionSet(u, g[u][i]);
        topoSort(g[u][i]);
    }
    stk.push(u);
    vis[u] = 2;
}

void initTopoSort(int n)
{
    cy = false;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            topoSort(i);
        }
    }
    while (!stk.empty())
    {
        order[findSet(stk.top())].push_back(stk.top());
        pos[stk.top()] = order[findSet(stk.top())].size();
        stk.pop();
    }
}

void clear(int n)
{
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
        order[i].clear();
        vis[i] = false;
    }

    initSet(n);
    edges.clear();
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
        clear(n);
        for (int i = 0; i < m; i++)
        {
            int tp, u, v;
            cin >> tp >> u >> v;

            if (tp == 1)
            {
                g[u].push_back(v);
            }
            else
            {
                edges.push_back({u, v});
            }
        }

        initTopoSort(n);
        if (cy)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;

            int grpu = findSet(u);
            int grpv = findSet(v);

            if (grpu == grpv)
            {
                if (pos[u] > pos[v])
                {
                    cout << v << " " << u << "\n";
                }
                else
                {
                    cout << u << " " << v << "\n";
                }
            }
            else
            {
                if (grpu < grpv)
                {
                    cout << u << " " << v << "\n";
                }
                else
                {
                    cout << v << " " << u << "\n";
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (auto u : g[i])
            {
                cout << i << " " << u << "\n";
            }
        }
    }
    return 0;
}
