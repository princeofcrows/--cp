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

int sizeSet[MX], parent[MX], black[MX], id[MX];

void initSet(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sizeSet[i] = 1;
        black[i] = 0;
        id[MX] = 0;
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
        black[a] += black[b];
        parent[b] = a;
    }
    else
    {
        sizeSet[b] += sizeSet[a];
        black[b] += black[a];
        parent[a] = b;
    }
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n, q;
    cin >> n >> q;

    initSet(n);

    while (q--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int u, v;
            cin >> u >> v;

            unionSet(u, v);
        }
        else
        {
            int v;
            cin >> v;
            if (t == 2)
            {
                int st = findSet(v);

                black[st] -= id[v];
                id[v] = 1 - id[v];
                black[st] += id[v];
            }
            else
            {
                int st = findSet(v);
                (black[st] ? yes() : no());
            }
        }
    }

    return 0;
}
